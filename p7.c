//쳲���������
#include <stdio.h>

int main(void)
{
	int new = 0;		//Ҫ�೤������

	while(1)
	{
		printf("������쳲��������еĳ��ȣ�(����0) ");
		scanf("%d",&new);
		int a = 1;
		int b = 1;
		int c = 0;
		int i = 0;
		if(new <= 0)
		{
			printf("������һ������0������\n");
		}
		else if(new < 2)
		{
			printf("%d",a);				//���1��1	
		}
		else printf("%d, %d",a,b);		//���2��1	
	
		for(i=0; i<new-2; i++)
		{
			c = a+b;
			printf(", ");
			printf("%d",c);
			a = b;
			b = c;
		}
		printf("\n");
	}
	return 0;
}
 