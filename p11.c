#include <stdio.h>

//输入姓名与年龄保存到文件中

int main(void)
{
	char name[32];
	int age = 0;
	char sex[16];
	FILE *nameInfo;
	char c;
	
	nameInfo = fopen("nameInfo.txt","w");
	if(!nameInfo)
	{
		printf("文件打开失败");
		return 1;
	}
	while(1)
	{
		printf("请输入您的姓名：");
		scanf("%s",name);
		printf("请输入您的年龄：");
		scanf("%d",&age);
		while(1)
		{
			printf("请输入您的性别（man/woman）：");
			scanf("%s",sex);
			
			if(!strcmp(sex,"man") || !strcmp(sex,"woman") || !strcmp(sex,"MAN") ||!strcmp(sex,"WOMAN"))
			{
				break;
			}
			else printf("您的输入有误，请重新输入\n");
		}
		
		fprintf(nameInfo,"姓名：%s \t\t 年龄：%d \t\t 性别：%s\n",name,age,sex);
		
		printf("是否继续输入（Y/N）：");
		fflush(stdin);
		scanf("%c",&c);
		if(c == 'y' || c == 'Y')
		{
			continue;
		}
		fclose(nameInfo);		
		break;
	}
	
	return 0;
}