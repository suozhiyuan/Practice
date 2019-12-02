#include <stdio.h>

void init(int n,int date[n][n])							//二维数组初始化函数
{
	for(int i =0; i < n; i++)
	{
		for(int j =0; j < n; j++)
		{
			date[i][j]=0;
		}
	}
}

int Clockwise_turn(int num, int date[num][num])			//转转转的函数
{
	int i = 0;
	int j = 0;
	int val = 1; 		//写入数存储位置
	int MAX = num*num;
	
	
	while(1)
	{
		while(j < num && date[i][j] ==0)	//向右
		{
			date[i][j++] = val++;
		}
		j--;

		if(val > MAX)
		{
			break;
		}else

		i++;
		while(i < num && date[i][j] ==0)	//向下
		{
			date[i++][j] = val++;
		}
		i--;
		
		if(val > MAX)
		{
			break;
		}
		
		j--;
		while(j < num && date[i][j] ==0)	//向左
		{
			date[i][j--] = val++;
		}
		j++;
		
		if(val > MAX)
		{
			break;
		}
		
		i--;
		while(i < num && date[i][j] ==0)	//向上
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

void show_assignment(int n,int date[n][n])				//打印二维数组函数
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
	
	printf("请输入顺时针螺旋阵列数：");
	scanf("%d", &num);
	int date[num][num];
	
	init(num, date);				//初始化
	
	Clockwise_turn(num, date);		//转起来~
	
	show_assignment(num, date);		//show一下
	
	return 0;	
}