#include <stdio.h>
//通过调用函数来输出一个金字塔
void show_Pyramid(int num, char c);

int main(void){
	
	int num = 0;
	char c = 0;

	while(1)
	{
		printf("请输入要打印的金字塔层数：");
		scanf("%d",&num);
		if(num > 0)
		{
			break;
		}
		else printf("必须输入大于0的数\n");	
	}
	
	while(1)
	{
		printf("请输入金字塔要用的砖块：");
		fflush(stdin);
		c = getc(stdin);
		if(c == ' ' || c == '\n' || c == '\t')
		{
			 printf("非法字符，请重新输入\n");
		}
		else break;
	}
		
	show_Pyramid(num, c);
	
	system("pause");
	return 0;
}

void show_Pyramid(int num, char c)
{
	int i = 0; 				//循环变量 控制当前打印层数
	int a = 0;				//循环变量 控制空格砖块的打印
	
	for(i = 1; i <= num; i++)
	{
		for(a = i; a <= num-1; a++)
		{
			printf(" ");
		}
		for(a = 0; a < i*2-1; a++)
		{
			printf("%c",c);
		}
		printf("\n");
	}	
}









