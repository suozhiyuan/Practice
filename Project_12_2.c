/**
* 有一个整形数组， a[3] = {7,2,5}， 要求使用指针实现数组成员由大到小的顺序排列，即
* 结果为：a[3] = {2,5,7};
*****************************************/

#include <stdio.h>


void change(int *x, int *y)
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

void arrange(int *num)
{
	int *num1 = &num[0];
	int *num2 = &num[1];
	int *num3 = &num[2];

	if(*num1 > *num2)
	{
		change(num1, num2);
	}
	if(*num1 > *num3)
	{
		change(num1, num3);
	}
	if(*num2 > *num3)
	{
		change(num2, num3);
	}
	
}

int main(void)
{
	int a[3] = {7, 2, 5};
	
	arrange(a);
	
	printf("a[3] = {%d, %d, %d}\n", a[0], a[1], a[2]);
	
	
	return 0;
}