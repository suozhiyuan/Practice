#include <stdio.h>

/*
int sumNum(int a)
{
	int i = 0;	
	int x = 0;
	
	for(i = 0; i < a+1; i++)
	{
		x += i;
	}
	
	return x;
}

int main(viod)
{
	int a = 0;
	int c = 0;
	
	printf("请输入要累加多少次：");
	scanf("%d",&a);
	
	c = sumNum(a);
	
	printf("%d",c);
	W
	return 0;
}*/

int hannuota(int n, char zhu_A[], char zhu_B[], char zhu_C[])
{
	if(n == 1)
	{
		printf("从 %s 移动到 %s\n",zhu_A, zhu_C);
		
		return;
	}
	
	hannuota(n-1, zhu_A, zhu_C, zhu_B);
	 
	printf("从 %s 移动到 %s\n", zhu_A, zhu_C);
	
	hannuota(n-1, zhu_B, zhu_A, zhu_C);
}

int main(void)
{
	int n = 0;
	
	printf("请输入汉诺塔盘子数：");
	
	scanf("%d", &n);
	
	hannuota(n, "A柱", "B柱", "C柱");
	
	return 0;
}

















