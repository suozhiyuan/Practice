// demo14-1.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *file; 


struct port 
{
	char name[16];
	int  status; //1: 激活  0：禁用
	char ip[16]; 
	char type[4]; //端口类型 LAN  WAN
};

//定义了5个端口变量

int port_num = 0;				//记录当前端口有多少                                                 
static int debug = 1;

void init(void) 
{
	//打开文件
	file = fopen("name_info.txt", "r");   
	if (!file) 
	{   //等效于 file == NULL  
		printf("文件打开失败"); 
		//return 1; 
		exit(1); 
	}
}

void login(void) 
{
	char name[32];
	char password[16];
	char line[128];
	char name_tmp[32];
	char password_tmp[16];
	char *ret;
	
	//输入用户名和密码
	while (1) 
	{
		system("cls");
		
		// 输入用户名和密码
		printf("请输入用户名：");
		scanf("%s", name);
		printf("请输入密码：");
		scanf("%s", password);
		
		//从文件中读取账号，并进行判断！
		while (1) 
		{
			//读一行
			ret = fgets(line, sizeof(line), file); //line:  "admin 123456\n"
			if (!ret) 
			{
				break;
			}		
			sscanf(line, "%s %s", name_tmp, password_tmp);
			if (!strcmp(name, name_tmp) && !strcmp(password, password_tmp)) 
			{
				break;
			}
		}
		
		if (ret) 
		{  //用户名和密码匹配成功
			break;
		} 
		else 
		{
			printf("用户名或密码错误!\n");
			system("pause");
			system("cls");
			
			fseek(file, 0, SEEK_SET); //把文件内部的位置指针设置到文件头
		}
	}
}

void create_user(void) 
{
	system("cls");
	printf("\n\n---创建账号---\n\n");
	printf("待实现...\n\n");
	printf("\n\n按任意键返回主菜单");
	fflush(stdin);
	getchar();
}

void ip_admin(void)
{
	system("cls");
	printf("\n\n---IP管理---\n\n");
	printf("待实现...\n\n");
	printf("\n\n按任意键返回主菜单");
	fflush(stdin);
	getchar();
}


void logout(void) 
{
	system("cls");
	fclose(file);
	exit(0);
}

void input_error(void) 
{
	system("cls");
	printf("\n\n输入错误！\n\n");
	printf("\n\n按任意键后，请重新输入\n\n");
	fflush(stdin);
	getchar();
}

void show_memu(void) 
{
	system("cls");
	// 打印功能菜单
	printf("---交换机后台管理---\n");
	printf("1. 创建账号\n");
	printf("2. IP管理\n");
	printf("3. 退出\n");
	printf("4. 端口管理\n");
	printf("请选择: ");
}

void show_port(struct port *port) 		// char buffer[4096]
{
	printf("名称[%s]\t状态[%s]\tIP[%-15s]\t类型[%s]\n", 
		port->name,
		port->status == 0 ? "禁用":"激活",
		port->ip,
		port->type);
}

void show_ports(struct port *ports) 
{
	system("cls");
	printf("---端口状态---\n");

	for (int n=0; n<port_num; n++) 
	{
		printf("PORT%d:\t", n+1);
		show_port(ports+n); 		//传递端口结构体的值
	}
	
	system("pause");
}

//void set_port1(void) {
void set_port(struct port *ports, int num) 
{
	//system("cls");
	printf("---设置PORT %d 端口---\n", num);
	
	printf("请输入端口名称: ");
	scanf("%s", ports->name);
	
	printf("请输入端口的状态：[0:禁止] [1:激活] ");
	scanf("%d", &(ports->status));
	
	printf("请输入端口的类型：[LAN 或 WAN] ");
	scanf("%s", ports->type);
	
	printf("请输入端口的IP地址: ");
	scanf("%s", ports->ip);
	
	system("pause");
}

/*************************
 *情况1： 目前不存在规则，直接动态分配规则所需得内存空间
 *    2:   已经存在端口规则，扩充内存空间，假设已有两个端口规则，则分配保存3个端口规则所需得空间
 ************************/
 
 // new_port	新结构体指针的大小
 // port_num	全局变量 几个端口
 
struct port *add_port(struct port *ports)
{
	struct port *new_port = NULL;
	
	if(port_num == 0)
	{
		new_port = malloc(sizeof(struct port));			//声明端口 new_port 结构体的动态大小
		set_port(new_port, port_num+1);					//新端口 new_port 写入
		port_num ++;
		return new_port;
	}
	else if(port_num > 0)
	{
		new_port = malloc((port_num+1)*sizeof(struct port));
		memcpy(new_port, ports, port_num*sizeof(struct port));
		set_port(new_port+port_num, port_num+1);		//相当于 set_port(new_port[port_num], port_num+1);
		port_num ++;
		free(ports);
		return new_port;
	}
	else 
	{
		printf("Warning! port_num <0 !\n");
	}
}

struct port *set_ports(struct port *ports) 			//n 条规则， malloc(n*sizeof(struct port))   
{
	char n;
	
	while(1) 
	{
		system("cls");
		printf("---端口设置---\n");
		for(int i=0; i< port_num; i++)
		{
			printf("%d. PORT%d\n", i+1, i+1);
		}
		printf("q. 返回\n");
		printf("+. 增加规则\n");
		printf("请选择: ");
		
		fflush(stdin);
		scanf("%c", &n);
		
		//'1'   cur=1  num =1   '0'->'10' cur=0  num*10+ cur =10 '1'->'101' cur=1 num*10+cur=101
		if(n == '+')
		{
			ports = add_port(ports);				//增加端口
			//return ports;
		}
		else if (n >= '0' && n <= '9' ) 
		{
			
			int num = 0, cur = 0;					//char转换int
			cur = n - '0';
			num =cur;
			do
			{
				scanf("%c", &n);					//接受输入缓冲区后边的字符
				if(n >= '0' && n <='9')
				{
					cur = n - '0';
					num = num*10+ cur;				//现有的值*10， 加上后来的个位数， 得到最后的值
				}
				else 
				{
					break;							//是值就会循环，没有数字就会退出
				}
			}
			while(1==1);
			
			//int num = n - '1';
			if(debug) printf("----num: %d\n", num);
			if(num >= 1 && num <= port_num)
			{
				set_port(ports+num-1, num);
			}
		} 
		else if (n == 'q') 
		{
			return ports;
		} 
		else 
		{
			input_error();
		}
	}
}

struct port *port_admin(struct port *ports) {
	char n;
	
	while(1) 
	{
		system("cls");
		printf("1. 查看端口\n");
		printf("2. 设置端口\n");
		printf("3. 返回主菜单\n");
		printf("请选择: ");
		
		fflush(stdin);
		scanf("%c", &n);
		if (n == '1') 
		{
			show_ports(ports);
		} 
		else if (n == '2') 
		{
			 ports = set_ports(ports);
		} 
		else if (n == '3') 
		{
			break;
		} 
		else 
		{
			input_error();
		} 
	}
}


struct port* init_port()
{
	//struct port ports[5];//局部变量  作用域
	struct port *ports=NULL, *port=NULL;
	
	
	ports = malloc(5*sizeof(struct port));
	
	port= ports;
	for(int i=0; i<5; i++, port++)
	{
		strcpy(port->name, "--- ---");
		strcpy(port->ip, "0.0.0.0");
		port->status = 0;
		strcpy(port->type, "LAN");
	}
	
	//show_ports(ports);
	return ports;
}


int main(void) 
{
	char n; //用户选择的菜单编号
	struct port *ports=NULL;
		
	init(); //初始化
	login(); //登录
	//for(int i=0; i<5; i++){
	//ports=init_port();
	
	//printf("--------------------\n");
	//show_ports(ports);
	
	//}
	
	while (1) 
	{
		show_memu();

		fflush(stdin);
		scanf("%c", &n);
		switch (n) 
		{
		case '1':
			create_user();
			break;
		case '2':
			ip_admin();	
			break;
		case '3':
			logout();
			break;
		case '4':
			ports = port_admin(ports);
			break;
		default:
			input_error();
			break;
		}
	}
	
	if(ports)
	{
		free(ports);
		ports = NULL;
	}
	
	return 0;
}
