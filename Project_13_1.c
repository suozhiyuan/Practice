/*****
*	学员名		语文	数学	英语	
*	学员1		74		76		89
*	学员2		98		65		89
*	学员3		78		54		99
*	学员4		84		96		85
*
*	需求1：计算每个学员的平均成绩
*	需求2：返回每个学员的最低分数
*
*	函数的数值传递需要使用指针来实现
*
**************************************/

#include <stdio.h>

	FILE * Student_grade;
	struct grade										//储存成绩的结构体
	{
		char Name[32];
		int Chinese_grade;
		int Math_grade;
		int English_grade;
	};
	
void init_info()										//文件中读取数据
{
	Student_grade = fopen("Student_grades.txt", "r");
	if(!Student_grade)
	{
		printf("文件 Student_grades.txt 打开失败！\n");
	}
}

void mean_grade(struct grade *grades)
{
	if(grades == NULL)
	{
		printf("Warning!!! grades is NULL.\n");
		return;
	}
	float mean_grade = (grades->Chinese_grade + grades->Math_grade + grades->English_grade) / 3.00;
	
	printf("%s：平均成绩为：%.2f\n",grades -> Name , mean_grade);
	
}

void change(int *x, int *y)								//比大小后交互值的函数
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

void low_grade(struct grade *grades)					//比大小的函数
{
	int num1 = grades->Chinese_grade;
	int num2 = grades->Math_grade;
	int num3 = grades->English_grade;
	
	if(num1 > num2)
	{
		change(&num1, &num2);
	}
	if(num1 > num3)
	{
		change(&num1, &num3);
	}
	if(num2 > num3)
	{
		change(&num2, &num3);
	}

	printf("%s：最低分数为%d\n\n", grades->Name, num1);
}

void course_mean(struct grade *grades, float *Chinese, float *Math, float *English)
{
	*Chinese += grades -> Chinese_grade;
	*Math += grades -> Math_grade;
	*English += grades -> English_grade;
}

int main(void)
{
	struct grade grades[4];
	init_info();										//负责所有初始化的函数
	float Chinese = 0;									//用来计算课程平均成绩
	float Math = 0;
	float English = 0;
	
	while(!feof(Student_grade))
	{
		int i = 0;
		i++;
		fscanf(Student_grade, "%s %d %d %d\n", grades[i].Name, &grades[i].Chinese_grade, &grades[i].Math_grade, &grades[i].English_grade);

		mean_grade(&grades[i]);								//获取平均数
		
		low_grade(&grades[i]);								//获取最低值	
		
		course_mean(&grades[i], &Chinese, &Math, &English);
	}
	
		printf("所有学员语文课平均成绩为：%.2f\n", Chinese / 4.00);
		printf("所有学员数学课平均成绩为：%.2f\n", Math / 4.00);
		printf("所有学员课英语平均成绩为：%.2f\n\n", English / 4.00);

	return 0;
}















