#include <stdio.h>
#include <string.h>

//һ����¼��
//����ֻ�����������
//����û���
//�û���Ϣ�ⲿ�ļ�����

int main(void)
{
	char name[32];					//�û�������û���
	char password[16];				//�û����������
	int password_number = 0;		//�����������
	char name_word[32];				//�ĵ���ȡ���û���
	char password_word[16];			//�ĵ���ȡ������
	char line_01[128];				//��ȡһ����Ϣ�洢��λ�� �˺�
	char line_02[128];				//��ȡһ����Ϣ�洢��λ�� ����
	FILE *name_info;				//�����ļ�����ָ��
	char *ret;						//�� fgets ���ڷ���ֵ
	
	name_info = fopen("User_information.txt","r");					//���ı���ʽ�򿪲���ȡ�ļ�
	if(!name_info)
	{
		printf("���ļ�ʧ�ܣ�");
		return 1;
	}

	fseek(name_info,0,SEEK_SET);								//���ļ��ڲ���λ��ָ��ŵ��ļ�0��λ��
	printf("�������û�����");									//�����û���
	scanf("%s",name);
	while(1)
	{			
		ret = fgets(line_01,sizeof(line_01),name_info);			//���ļ��ж�ȡһ���ַ����ŵ� line_01 �У�ret���ڷ���ֵΪ0ʱ���ж�
		sscanf(line_01,"%s %s",name_word,password_word);		//�� line_01 �ж�ȡ�����ַ������ŵ� �������� ��
		if(!strcmp(name,name_word))								//�Ƚ��û��������û�����
		{
			printf("���������룺");								//��������
			break;
		}
		if(!ret)												//�ļ�����Ĵ���
		{
			printf("�û��������ڣ�����������\n");	
			fseek(name_info,0,SEEK_SET);						//���ļ��ڲ���λ��ָ��ŵ��ļ�0��λ��
			printf("�������û�����");							//�����û���
			scanf("%s",name);
		}
	}

	
	for(password_number = 0; password_number<3; password_number++)
	{								
		scanf("%s",password);										//��������

		if(!strcmp(password,password_word))
		{
			printf("---��¼�ɹ�---\n");
			printf("1.�����˺�\n");
			printf("2.IP����\n");
			printf("3.�˳�\n");
			printf("��ѡ��...");
			break;
		}else if (password_number<2)
		printf("�������%d�Σ�����������",password_number+1);
		fseek(name_info,0,SEEK_SET);								//���ļ��ڲ���λ��ָ��ŵ��ļ�0��λ��
	}
	if(password_number > 2)
	{
		printf("����������������࣬���Ժ����ԡ�");
	}
	
	return 0;
}



































