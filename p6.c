#include <stdio.h>
#include <string.h>


//�������ʽ���
/**
int main(void)
{
	char name[64];
	int  num;			//�ַ�������
	int  i = 0;
	
	printf("������һ�λ���");
	//scanf("%s",name);
	fgets(name,sizeof(name),stdin);			//��һ�����뺯����������еĿո�����
	
	num = strlen(name);						//ͨ��strlen�����ó��ַ����ĳ���
	printf("��������ֽڳ���Ϊ��%d",num);
	
	for(num; num>=0; num--)
	{
		printf("%c",name[num]);
	}
		
	return 0;
}
*/

//�Ըı��ַ������ݷ�ʽ���
int main(void)
{
	char name[64];
	int num =0;			//���� 
	char box;			//���ַ��������м��ŵĺ���
	int i = 0;		//ѭ��
	int c = 0;		//����һ��ѭ�� num/2��ֵ
	
	printf("����һ���ַ�����");
	fgets(name,sizeof(name),stdin);		//���뺯����������еĿո�����
	num = strlen(name);					//ͨ��strlen�����ó��ַ����ĳ���
	c = num/2;
	
	for(i = 0; i <c ; i++)
	{
		box = name[i];					//name[i] ��һ��ѭ���������еĵ�"i"����
		name[i] = name[num-i-1];		//name[num-i-1] ��һ��ѭ���������е�"�ַ�������-i-1"�������ַ���Ĭ������и�\0��
		name[num-i-1] = box;
	}
	printf("%s\n",name);	
	
	return 0;
}


