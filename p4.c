#include <stdio.h>
#include <string.h>

//一个登录器
//密码只允许错误三次
//多个用户名
//用户信息外部文件包含

int main(void)
{
	char name[32];					//用户输入的用户名
	char password[16];				//用户输入的密码
	int password_number = 0;		//密码输入次数
	char name_word[32];				//文档读取的用户名
	char password_word[16];			//文档读取的密码
	char line_01[128];				//读取一行信息存储的位置 账号
	char line_02[128];				//读取一行信息存储的位置 密码
	FILE *name_info;				//定义文件变量指针
	char *ret;						//用 fgets 的于返回值
	
	name_info = fopen("User_information.txt","r");					//以文本方式打开并读取文件
	if(!name_info)
	{
		printf("打开文件失败！");
		return 1;
	}

	fseek(name_info,0,SEEK_SET);								//把文件内部的位置指针放到文件0的位置
	printf("请输入用户名：");									//输入用户名
	scanf("%s",name);
	while(1)
	{			
		ret = fgets(line_01,sizeof(line_01),name_info);			//从文件中读取一行字符串放到 line_01 中，ret用于返回值为0时的判断
		sscanf(line_01,"%s %s",name_word,password_word);		//从 line_01 中读取两段字符串，放到 两个参数 中
		if(!strcmp(name,name_word))								//比较用户名库与用户输入
		{
			printf("请输入密码：");								//输入密码
			break;
		}
		if(!ret)												//文件读完的处理
		{
			printf("用户名不存在，请重新输入\n");	
			fseek(name_info,0,SEEK_SET);						//把文件内部的位置指针放到文件0的位置
			printf("请输入用户名：");							//输入用户名
			scanf("%s",name);
		}
	}

	
	for(password_number = 0; password_number<3; password_number++)
	{								
		scanf("%s",password);										//输入密码

		if(!strcmp(password,password_word))
		{
			printf("---登录成功---\n");
			printf("1.创建账号\n");
			printf("2.IP管理\n");
			printf("3.退出\n");
			printf("请选择...");
			break;
		}else if (password_number<2)
		printf("密码错误%d次，请重新输入",password_number+1);
		fseek(name_info,0,SEEK_SET);								//把文件内部的位置指针放到文件0的位置
	}
	if(password_number > 2)
	{
		printf("您密码输入次数过多，请稍后再试。");
	}
	
	return 0;
}



































