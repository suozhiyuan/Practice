#include <stdio.h>

//像文件中输入二进制数据
//读取文件中的二进制数据

int main(void)
{
	char name[32]={0};
	int age = 0;
	FILE *file;
	
	file = fopen("info1.txt","rb");
	if(!file)
	{
		printf("文件读取失败!\n");
		return 1;
	}
	
	/*
	printf("请输入您的姓名：");
	scanf("%s", name);
	
	printf("请输入您的年龄：");
	scanf("%d", &age);
	
	fwrite(name,sizeof(char),sizeof(name),file);
	fwrite(&age,sizeof(int),1,file);
	*/
	/**/
	fread(name,sizeof(char),sizeof(name),file);
	fread(&age,sizeof(int),1,file);
	
	printf("%s\n",name);
	printf("%d",age);
	
	fclose(file);
	
	return 0;
}