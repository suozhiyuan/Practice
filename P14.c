#include <stdio.h>

// ��Ŀ1������ļ����ж��� �ַ�
// ��Ŀ2������ļ��ж����� ����
// ����ļ��еĴ���

/*
**����һ
int main(void)
{
	FILE *file;
	char ret;			//����ַ��������ж�������ٴ��ַ�
	int x = 0;			//�����ж��ַ���ѭ������
	char line[256];		//����ַ����������ж�����˶����д���
	int y = 0;			//�����ж��ַ���ѭ������
	
	file = fopen("p14.c","r");
	if(!file)
	{
		printf("�ļ���ʧ�ܣ�\n");
		return 1;
	}
	
	while((ret = fgetc(file))!=EOF)		//fgetc ʧ�ܷ���EOF
	{
		x++;
	}
	
	fflush(stdin);
	fseek(file,0,SEEK_SET);					//�����ļ�ָ��λ�õ��ļ���ʼ
	
	while(fgets(line,sizeof(line),file))	//fgets ʧ�ܷ��� 0
	{
		//printf("%s",line);
		fputs(line,stdout);
		y++;
	}

	printf("\n���ļ���%d���ַ���\n",x);
	printf("���ļ���%d�д��롣\n",y);
	
	fclose(file);
	
	return 0;
}*/

// ��Ŀ1������ļ����ж��� �ַ�
// ��Ŀ2������ļ��ж����� ����
// ����ļ��еĴ���
//������

int main(void)
{
	FILE *file;
	char c;					//��ȡһ���ַ�����¼�Ĳ���
	int a = 0;				//��¼�����ַ���
	int b = 1;				//��¼��������
	
	file = fopen("p14.c","r");
	if(!file)
	{
		printf("�ļ���ʧ�ܣ�\n");
	}
	
	while((c = fgetc(file))!=EOF)
	{
		a++;
		fputc(c,stdout);
		
		if(c == '\n')
		{
			b++;
		}
	}
	
	printf("\n���ļ�һ����%d���ַ���\n", a);
	printf("���ļ�һ����%d�д��롣\n", b);
	
	return 0;
}