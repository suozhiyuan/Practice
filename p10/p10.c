#include <stdio.h>

//读取文件中一行的内容 循环打印出所有内容
//使用fgets实现

int main(void)
{
	FILE *file1;
	FILE *file2;
	char line[128];
	char *ret;
	
	file1 = fopen("p10.c","r");
	file2 = fopen("p10_1.c","w");
	if(!file1 && !file2)
	{
		printf("文件打开失败\n");
		return 1;
	}
	
	//普通写法
	/*while(1)
	{
		ret = fgets(line,sizeof(line),file1);
		if(!ret)
		{
			break;
		}
		//fputs(line,file2);
		printf("%s",line);
	}*/
	
	//高逼格写法
	while(fgets(line,sizeof(line),file1))
	{
		fputs(line,file2);
		//printf("%s",line);
	}
	
	fclose(file1);
	fclose(file2);
	
	return 0;
}