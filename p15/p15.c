#include <stdio.h>

//ͨ���û������û�����Ѱ���ļ��ж�Ӧ��������Ϣ

int main(void)
{
	FILE *file;	
	file = fopen("phone.txt","r");
	if(!file)
	{
		printf("�ļ���ʧ��");
		return 1;
	}
	
	while(1)
	{
		int a = 0;							//�����һ��ѭ���������ı���
		char name[32] = {0};
		char name_tmp[32] = {0};			//ִ��ѭ��ʱ�����в�����ʼ��
		char tel[16] = {0};
		char addr[128] = {0};
		fseek(file,0,SEEK_SET);				//�ļ�ָ���ʼ��
		
		printf("��������Ҫ��ѯ���û���");
		scanf("%s",name);
		
		while(!feof(file))
		{
			fscanf(file,"%s Tel��%s Addr��%s",name_tmp,tel,addr);
			if(!strcmp(name , name_tmp))
			{
				a = 1;
				break;
			}
		}
		if(a)
		{
			printf("%s�ĵ绰�ǣ�%s\n",name,tel);	
		}		
		else printf("��������û�%s�����ڡ�\n",name);
	}
	
	fclose(file);
	return 0;
}