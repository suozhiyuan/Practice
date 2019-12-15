// demo14-1.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

FILE *file; 


struct port 
{
	char name[16];
	int  status; //1: ����  0������
	char ip[16]; 
	char type[4]; //�˿����� LAN  WAN
};

//������5���˿ڱ���

int port_num = 0;				//��¼��ǰ�˿��ж���                                                 
static int debug = 1;

void init(void) 
{
	//���ļ�
	file = fopen("name_info.txt", "r");   
	if (!file) 
	{   //��Ч�� file == NULL  
		printf("�ļ���ʧ��"); 
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
	
	//�����û���������
	while (1) 
	{
		system("cls");
		
		// �����û���������
		printf("�������û�����");
		scanf("%s", name);
		printf("���������룺");
		scanf("%s", password);
		
		//���ļ��ж�ȡ�˺ţ��������жϣ�
		while (1) 
		{
			//��һ��
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
		{  //�û���������ƥ��ɹ�
			break;
		} 
		else 
		{
			printf("�û������������!\n");
			system("pause");
			system("cls");
			
			fseek(file, 0, SEEK_SET); //���ļ��ڲ���λ��ָ�����õ��ļ�ͷ
		}
	}
}

void create_user(void) 
{
	system("cls");
	printf("\n\n---�����˺�---\n\n");
	printf("��ʵ��...\n\n");
	printf("\n\n��������������˵�");
	fflush(stdin);
	getchar();
}

void ip_admin(void)
{
	system("cls");
	printf("\n\n---IP����---\n\n");
	printf("��ʵ��...\n\n");
	printf("\n\n��������������˵�");
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
	printf("\n\n�������\n\n");
	printf("\n\n�������������������\n\n");
	fflush(stdin);
	getchar();
}

void show_memu(void) 
{
	system("cls");
	// ��ӡ���ܲ˵�
	printf("---��������̨����---\n");
	printf("1. �����˺�\n");
	printf("2. IP����\n");
	printf("3. �˳�\n");
	printf("4. �˿ڹ���\n");
	printf("��ѡ��: ");
}

void show_port(struct port *port) 		// char buffer[4096]
{
	printf("����[%s]\t״̬[%s]\tIP[%-15s]\t����[%s]\n", 
		port->name,
		port->status == 0 ? "����":"����",
		port->ip,
		port->type);
}

void show_ports(struct port *ports) 
{
	system("cls");
	printf("---�˿�״̬---\n");

	for (int n=0; n<port_num; n++) 
	{
		printf("PORT%d:\t", n+1);
		show_port(ports+n); 		//���ݶ˿ڽṹ���ֵ
	}
	
	system("pause");
}

//void set_port1(void) {
void set_port(struct port *ports, int num) 
{
	//system("cls");
	printf("---����PORT %d �˿�---\n", num);
	
	printf("������˿�����: ");
	scanf("%s", ports->name);
	
	printf("������˿ڵ�״̬��[0:��ֹ] [1:����] ");
	scanf("%d", &(ports->status));
	
	printf("������˿ڵ����ͣ�[LAN �� WAN] ");
	scanf("%s", ports->type);
	
	printf("������˿ڵ�IP��ַ: ");
	scanf("%s", ports->ip);
	
	system("pause");
}

/*************************
 *���1�� Ŀǰ�����ڹ���ֱ�Ӷ�̬�������������ڴ�ռ�
 *    2:   �Ѿ����ڶ˿ڹ��������ڴ�ռ䣬�������������˿ڹ�������䱣��3���˿ڹ�������ÿռ�
 ************************/
 
 // new_port	�½ṹ��ָ��Ĵ�С
 // port_num	ȫ�ֱ��� �����˿�
 
struct port *add_port(struct port *ports)
{
	struct port *new_port = NULL;
	
	if(port_num == 0)
	{
		new_port = malloc(sizeof(struct port));			//�����˿� new_port �ṹ��Ķ�̬��С
		set_port(new_port, port_num+1);					//�¶˿� new_port д��
		port_num ++;
		return new_port;
	}
	else if(port_num > 0)
	{
		new_port = malloc((port_num+1)*sizeof(struct port));
		memcpy(new_port, ports, port_num*sizeof(struct port));
		set_port(new_port+port_num, port_num+1);		//�൱�� set_port(new_port[port_num], port_num+1);
		port_num ++;
		free(ports);
		return new_port;
	}
	else 
	{
		printf("Warning! port_num <0 !\n");
	}
}

struct port *set_ports(struct port *ports) 			//n ������ malloc(n*sizeof(struct port))   
{
	char n;
	
	while(1) 
	{
		system("cls");
		printf("---�˿�����---\n");
		for(int i=0; i< port_num; i++)
		{
			printf("%d. PORT%d\n", i+1, i+1);
		}
		printf("q. ����\n");
		printf("+. ���ӹ���\n");
		printf("��ѡ��: ");
		
		fflush(stdin);
		scanf("%c", &n);
		
		//'1'   cur=1  num =1   '0'->'10' cur=0  num*10+ cur =10 '1'->'101' cur=1 num*10+cur=101
		if(n == '+')
		{
			ports = add_port(ports);				//���Ӷ˿�
			//return ports;
		}
		else if (n >= '0' && n <= '9' ) 
		{
			
			int num = 0, cur = 0;					//charת��int
			cur = n - '0';
			num =cur;
			do
			{
				scanf("%c", &n);					//�������뻺������ߵ��ַ�
				if(n >= '0' && n <='9')
				{
					cur = n - '0';
					num = num*10+ cur;				//���е�ֵ*10�� ���Ϻ����ĸ�λ���� �õ�����ֵ
				}
				else 
				{
					break;							//��ֵ�ͻ�ѭ����û�����־ͻ��˳�
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
		printf("1. �鿴�˿�\n");
		printf("2. ���ö˿�\n");
		printf("3. �������˵�\n");
		printf("��ѡ��: ");
		
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
	//struct port ports[5];//�ֲ�����  ������
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
	char n; //�û�ѡ��Ĳ˵����
	struct port *ports=NULL;
		
	init(); //��ʼ��
	login(); //��¼
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
