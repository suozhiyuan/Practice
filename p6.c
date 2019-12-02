#include <stdio.h>
#include <string.h>


//以输出方式达成
/**
int main(void)
{
	char name[64];
	int  num;			//字符串长度
	int  i = 0;
	
	printf("请输入一段话：");
	//scanf("%s",name);
	fgets(name,sizeof(name),stdin);			//换一种输入函数解决输入中的空格问题
	
	num = strlen(name);						//通过strlen函数得出字符串的长度
	printf("你输入的字节长度为：%d",num);
	
	for(num; num>=0; num--)
	{
		printf("%c",name[num]);
	}
		
	return 0;
}
*/

//以改变字符串内容方式完成
int main(void)
{
	char name[64];
	int num =0;			//长度 
	char box;			//两字符交换的中间存放的盒子
	int i = 0;		//循环
	int c = 0;		//减少一次循环 num/2的值
	
	printf("输入一个字符串：");
	fgets(name,sizeof(name),stdin);		//输入函数解决输入中的空格问题
	num = strlen(name);					//通过strlen函数得出字符串的长度
	c = num/2;
	
	for(i = 0; i <c ; i++)
	{
		box = name[i];					//name[i] 第一次循环拿数组中的第"i"个数
		name[i] = name[num-i-1];		//name[num-i-1] 第一次循环拿数组中第"字符串长度-i-1"的数（字符串默认最后有个\0）
		name[num-i-1] = box;
	}
	printf("%s\n",name);	
	
	return 0;
}


