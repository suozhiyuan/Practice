#include <stdio.h>
//从文件中读取特定格式的内容

int main(void)
{
	FILE *info;
	char name[32];
	char sex[16];
	int ret;
	
	info = fopen("F:\\C++\\P11\\nameInfo.txt","r");
	if(!info)
	{
		printf("文件打开失败!\n");
	}
	
	//普通写法
	/*while(1)
	{
		ret = fscanf(info,"姓名：%s 性别：%s\n",name,sex);
		if(ret == EOF)
		{
			break;
		}
		printf("姓名：%s 性别：%s\n",name,sex);
	}*/
	
	//高逼格写法
	/**/
	while(fscanf(info,"姓名：%s 性别：%s\n",name,sex) != EOF)
	{
		printf("姓名：%s 性别：%s\n",name,sex);
	}	
	
	return 0;
}