/**
*	实现一个函数，函数完成如下功能：
*	1.函数的输入为一个数组，数组的成员个数不定（即：可能为0个，也可能为多个）
*	2.函数找到成员的最大元素和最小元素，并能让函数的调用者知道最大元素和最小元素是哪一个
*	a[10] = {7,2,5,9,8,4,3,6,1,0}
************************************************/

#include <stdio.h>


int MAX_LEAST(int a[], int length)
{
	int MAX_tmp = 0;
	int LEAST_tmp = 0;
	
	for(int i = 0; i < length; i++)
	{
		if(a[i] > tmp)
		{
			tmp = a[i];
		}
	}
	
	return tmp;
}


int main(void)
{
	int a[10] = {7,2,5,9,8,4,3,6,1,0};
	int *p = &a[0];
	
	int length = sizeof(a)/sizeof(int);				//求数组长度

	printf("数组为：a[10] = {7,2,5,9,8,4,3,6,1,0}\n\n");
	
	//最大成员：
	printf("数组的最大成员是：%d\n", MAX(a, length));
	
	//最小成员：
	printf("数组的最小成员是：%d\n", LEAST(a, length));
	
	return 0;
}