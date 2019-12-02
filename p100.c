#include <stdio.h>

void init(int n,int date[n][n])							//��ά�����ʼ������
{
	for(int i =0; i < n; i++)
	{
		for(int j =0; j < n; j++)
		{
			date[i][j]=0;
		}
	}
}

int Clockwise_turn(int num, int date[num][num])			//תתת�ĺ���
{
	int i = 0;
	int j = 0;
	int val = 1; 		//д�����洢λ��
	int MAX = num*num;
	
	
	while(1)
	{
		while(j < num && date[i][j] ==0)	//����
		{
			date[i][j++] = val++;
		}
		j--;

		if(val > MAX)
		{
			break;
		}else

		i++;
		while(i < num && date[i][j] ==0)	//����
		{
			date[i++][j] = val++;
		}
		i--;
		
		if(val > MAX)
		{
			break;
		}
		
		j--;
		while(j < num && date[i][j] ==0)	//����
		{
			date[i][j--] = val++;
		}
		j++;
		
		if(val > MAX)
		{
			break;
		}
		
		i--;
		while(i < num && date[i][j] ==0)	//����
		{
			date[i--][j] = val++;
		}
		i++;
		
		if(val > MAX)
		{
			break;
		}
		j++;
	}	
}

void show_assignment(int n,int date[n][n])				//��ӡ��ά���麯��
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("%d\t", date[i][j]);
		}
		printf("\n\n");
	}
}

int main(void)
{
	int num = 0;
	
	printf("������˳ʱ��������������");
	scanf("%d", &num);
	int date[num][num];
	
	init(num, date);				//��ʼ��
	
	Clockwise_turn(num, date);		//ת����~
	
	show_assignment(num, date);		//showһ��
	
	return 0;	
}