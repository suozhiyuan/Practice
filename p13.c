#include <stdio.h>

//���ļ����������������
//��ȡ�ļ��еĶ���������

int main(void)
{
	char name[32]={0};
	int age = 0;
	FILE *file;
	
	file = fopen("info1.txt","rb");
	if(!file)
	{
		printf("�ļ���ȡʧ��!\n");
		return 1;
	}
	
	/*
	printf("����������������");
	scanf("%s", name);
	
	printf("�������������䣺");
	scanf("%d", &age);
	
	fwrite(name,sizeof(char),sizeof(name),file);
	fwrite(&age,sizeof(int),1,file);
	*/
	/**/
	fread(name,sizeof(char),sizeof(name),file);
	fread(&age,sizeof(int),1,file);
	
	printf("%s\n",name);
	printf("%d",age);
	
	fclose(file);
	
	return 0;
}