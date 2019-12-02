#include <stdio.h>

int main(void)
{
	int a = 1;
	int b = 1;
	
	for(b=1;b<10;b++)
	{
		for(a=1;a<=b;a++)
		{	
			printf("%dX%d=%d\t",a,b,a*b);
		}
		printf("\n");
	}

	return 0;
}
