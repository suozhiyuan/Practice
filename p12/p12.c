#include <stdio.h>
//���ļ��ж�ȡ�ض���ʽ������

int main(void)
{
	FILE *info;
	char name[32];
	char sex[16];
	int ret;
	
	info = fopen("F:\\C++\\P11\\nameInfo.txt","r");
	if(!info)
	{
		printf("�ļ���ʧ��!\n");
	}
	
	//��ͨд��
	/*while(1)
	{
		ret = fscanf(info,"������%s �Ա�%s\n",name,sex);
		if(ret == EOF)
		{
			break;
		}
		printf("������%s �Ա�%s\n",name,sex);
	}*/
	
	//�߱Ƹ�д��
	/**/
	while(fscanf(info,"������%s �Ա�%s\n",name,sex) != EOF)
	{
		printf("������%s �Ա�%s\n",name,sex);
	}	
	
	return 0;
}