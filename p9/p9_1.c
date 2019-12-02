#include <stdio.h>
//将文件内容复制到另一个文件
//使用fputc操作

int main(void)
{
	FILE *file1;
	FILE *file2;
	char c;
	
	file1 = fopen("p9.c","r");
	file2 = fopen("p9_2.c","w");
	if(!file1 && !file2)
	{
		printf("文件打开失败\n");
	}
	//普通写法
	/*while(1)
	{
		c = fgetc(file1);
		if(c == EOF)
		{
			break;
		}
		fputc(c,file2);
	}*/
	
	//高逼格写法
	while((c = fgetc(file1))!= EOF)
	{
		fputc(c,file2);
	}
		
	fclose(file1);
	fclose(file2);
	
	return 0;
}