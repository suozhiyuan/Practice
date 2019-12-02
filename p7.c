//斐波那契数列
#include <stdio.h>

int main(void)
{
	int new = 0;		//要多长的数列

	while(1)
	{
		printf("请输入斐波那契数列的长度：(大于0) ");
		scanf("%d",&new);
		int a = 1;
		int b = 1;
		int c = 0;
		int i = 0;
		if(new <= 0)
		{
			printf("请输入一个大于0的数。\n");
		}
		else if(new < 2)
		{
			printf("%d",a);				//输出1个1	
		}
		else printf("%d, %d",a,b);		//输出2个1	
	
		for(i=0; i<new-2; i++)
		{
			c = a+b;
			printf(", ");
			printf("%d",c);
			a = b;
			b = c;
		}
		printf("\n");
	}
	return 0;
}
 