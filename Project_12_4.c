/**
*	ʵ��һ��������ʹ��ָ�����������ַ�����
*	�������룺 ����Դ�ַ�����ָ�룬Ŀ���ַ�����ָ��
******************************************************/

#include <stdio.h>
#include <string.h>

void splice(unsigned char *chars_a, unsigned char *chars_b, unsigned char *chars_c)
{
	int a = 0;
	while(*chars_a)								//����һ���ַ������õ� Ŀ���ַ���
	{
		*chars_c++ = *chars_a++;
	}
	
	while(*chars_b)								//���ڶ����ַ������õ� Ŀ���ַ���
	{
		*chars_c++ = *chars_b++;
	}

	return;
}

int main(void)
{
	unsigned char chars_1[10] = "�л�����";
	unsigned char chars_2[10] = "���͹�";
	unsigned char chars_3[20] = "";
	
	unsigned char *chars_a = chars_1;
	unsigned char *chars_b = chars_2;
	unsigned char *chars_c = chars_3;
	
	splice(chars_1, chars_2, chars_3);
	
	printf("ƴ�ӽ��Ϊ��%s", chars_c);
	
	return 0;	
}