/**
*	ʵ��һ������������������¹��ܣ�
*	1.����������Ϊһ�����飬����ĳ�Ա������������������Ϊ0����Ҳ����Ϊ�����
*	2.�����ҵ���Ա�����Ԫ�غ���СԪ�أ������ú����ĵ�����֪�����Ԫ�غ���СԪ������һ��
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
	
	int length = sizeof(a)/sizeof(int);				//�����鳤��

	printf("����Ϊ��a[10] = {7,2,5,9,8,4,3,6,1,0}\n\n");
	
	//����Ա��
	printf("���������Ա�ǣ�%d\n", MAX(a, length));
	
	//��С��Ա��
	printf("�������С��Ա�ǣ�%d\n", LEAST(a, length));
	
	return 0;
}