#include <stdio.h>
//���ļ����ݸ��Ƶ���һ���ļ�
//ʹ��fputc����

int main(void)
{
	FILE *file1;
	FILE *file2;
	char c;
	
	file1 = fopen("p9.c","r");
	file2 = fopen("p9_2.c","w");
	if(!file1 && !file2)
	{
		printf("�ļ���ʧ��\n");
	}
	//��ͨд��
	/*while(1)
	{
		c = fgetc(file1);
		if(c == EOF)
		{
			break;
		}
		fputc(c,file2);
	}*/
	
	//�߱Ƹ�д��
	while((c = fgetc(file1))!= EOF)
	{
		fputc(c,file2);
	}
		
	fclose(file1);
	fclose(file2);
	
	return 0;
}