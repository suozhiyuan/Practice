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
	
	printf("������Ҫ�ۼӶ��ٴΣ�");
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
		printf("�� %s �ƶ��� %s\n",zhu_A, zhu_C);
		
		return;
	}
	
	hannuota(n-1, zhu_A, zhu_C, zhu_B);
	 
	printf("�� %s �ƶ��� %s\n", zhu_A, zhu_C);
	
	hannuota(n-1, zhu_B, zhu_A, zhu_C);
}

int main(void)
{
	int n = 0;
	
	printf("�����뺺ŵ����������");
	
	scanf("%d", &n);
	
	hannuota(n, "A��", "B��", "C��");
	
	return 0;
}

















