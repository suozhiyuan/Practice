/**
*	实现一个函数，使用指针连接两个字符串。
*	函数输入： 两个源字符串的指针，目的字符串的指针
******************************************************/

#include <stdio.h>
#include <string.h>

void splice(unsigned char *chars_a, unsigned char *chars_b, unsigned char *chars_c)
{
	int a = 0;
	while(*chars_a)								//将第一段字符串放置到 目的字符串
	{
		*chars_c++ = *chars_a++;
	}
	
	while(*chars_b)								//将第二段字符串放置到 目的字符串
	{
		*chars_c++ = *chars_b++;
	}

	return;
}

int main(void)
{
	unsigned char chars_1[10] = "中华人民";
	unsigned char chars_2[10] = "共和国";
	unsigned char chars_3[20] = "";
	
	unsigned char *chars_a = chars_1;
	unsigned char *chars_b = chars_2;
	unsigned char *chars_c = chars_3;
	
	splice(chars_1, chars_2, chars_3);
	
	printf("拼接结果为：%s", chars_c);
	
	return 0;	
}