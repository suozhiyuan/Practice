#include <stdio.h>

//��ȡ�ļ���һ�е����� ѭ����ӡ����������
//ʹ��fgetsʵ��

int main(void)
{
	FILE *file1;
	FILE *file2;
	char line[128];
	char *ret;
	
	file1 = fopen("p10.c","r");
	file2 = fopen("p10_1.c","w");
	if(!file1 && !file2)
	{
		printf("�ļ���ʧ��\n");
		return 1;
	}
	
	//��ͨд��
	/*while(1)
	{
		ret = fgets(line,sizeof(line),file1);
		if(!ret)
		{
			break;
		}
		//fputs(line,file2);
		printf("%s",line);
	}*/
	
	//�߱Ƹ�д��
	while(fgets(line,sizeof(line),file1))
	{
		fputs(line,file2);
		//printf("%s",line);
	}
	
	fclose(file1);
	fclose(file2);
	
	return 0;
}