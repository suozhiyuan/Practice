#include <stdio.h>

//�������������䱣�浽�ļ���

int main(void)
{
	char name[32];
	int age = 0;
	char sex[16];
	FILE *nameInfo;
	char c;
	
	nameInfo = fopen("nameInfo.txt","w");
	if(!nameInfo)
	{
		printf("�ļ���ʧ��");
		return 1;
	}
	while(1)
	{
		printf("����������������");
		scanf("%s",name);
		printf("�������������䣺");
		scanf("%d",&age);
		while(1)
		{
			printf("�����������Ա�man/woman����");
			scanf("%s",sex);
			
			if(!strcmp(sex,"man") || !strcmp(sex,"woman") || !strcmp(sex,"MAN") ||!strcmp(sex,"WOMAN"))
			{
				break;
			}
			else printf("����������������������\n");
		}
		
		fprintf(nameInfo,"������%s \t\t ���䣺%d \t\t �Ա�%s\n",name,age,sex);
		
		printf("�Ƿ�������루Y/N����");
		fflush(stdin);
		scanf("%c",&c);
		if(c == 'y' || c == 'Y')
		{
			continue;
		}
		fclose(nameInfo);		
		break;
	}
	
	return 0;
}