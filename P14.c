#include <stdio.h>

// 题目1：输出文件有有多少 字符
// 题目2：输出文件有多少行 代码
// 输出文件中的代码

/*
**方法一
int main(void)
{
	FILE *file;
	char ret;			//输出字符，用来判断输出多少次字符
	int x = 0;			//用作判断字符的循环参数
	char line[256];		//输出字符串，用来判断输出了多少行代码
	int y = 0;			//用作判断字符的循环参数
	
	file = fopen("p14.c","r");
	if(!file)
	{
		printf("文件打开失败！\n");
		return 1;
	}
	
	while((ret = fgetc(file))!=EOF)		//fgetc 失败返回EOF
	{
		x++;
	}
	
	fflush(stdin);
	fseek(file,0,SEEK_SET);					//重置文件指针位置到文件开始
	
	while(fgets(line,sizeof(line),file))	//fgets 失败返回 0
	{
		//printf("%s",line);
		fputs(line,stdout);
		y++;
	}

	printf("\n该文件有%d个字符。\n",x);
	printf("该文件有%d行代码。\n",y);
	
	fclose(file);
	
	return 0;
}*/

// 题目1：输出文件有有多少 字符
// 题目2：输出文件有多少行 代码
// 输出文件中的代码
//方法二

int main(void)
{
	FILE *file;
	char c;					//读取一个字符所记录的参数
	int a = 0;				//记录代码字符数
	int b = 1;				//记录代码行数
	
	file = fopen("p14.c","r");
	if(!file)
	{
		printf("文件打开失败！\n");
	}
	
	while((c = fgetc(file))!=EOF)
	{
		a++;
		fputc(c,stdout);
		
		if(c == '\n')
		{
			b++;
		}
	}
	
	printf("\n该文件一共有%d个字符。\n", a);
	printf("该文件一共有%d行代码。\n", b);
	
	return 0;
}