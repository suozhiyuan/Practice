#include <stdio.h>

//通过用户输入用户名来寻找文件中对应的其他信息

int main(void)
{
	FILE *file;	
	file = fopen("phone.txt","r");
	if(!file)
	{
		printf("文件打开失败");
		return 1;
	}
	
	while(1)
	{
		int a = 0;							//清除上一次循环所产生的变量
		char name[32] = {0};
		char name_tmp[32] = {0};			//执行循环时将所有参数初始化
		char tel[16] = {0};
		char addr[128] = {0};
		fseek(file,0,SEEK_SET);				//文件指针初始化
		
		printf("请输入您要查询的用户：");
		scanf("%s",name);
		
		while(!feof(file))
		{
			fscanf(file,"%s Tel：%s Addr：%s",name_tmp,tel,addr);
			if(!strcmp(name , name_tmp))
			{
				a = 1;
				break;
			}
		}
		if(a)
		{
			printf("%s的电话是：%s\n",name,tel);	
		}		
		else printf("您输入的用户%s不存在。\n",name);
	}
	
	fclose(file);
	return 0;
}