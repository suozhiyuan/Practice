/*****
*	ѧԱ��		����	��ѧ	Ӣ��	
*	ѧԱ1		74		76		89
*	ѧԱ2		98		65		89
*	ѧԱ3		78		54		99
*	ѧԱ4		84		96		85
*
*	����1������ÿ��ѧԱ��ƽ���ɼ�
*	����2������ÿ��ѧԱ����ͷ���
*
*	��������ֵ������Ҫʹ��ָ����ʵ��
*
**************************************/

#include <stdio.h>

	FILE * Student_grade;
	struct grade										//����ɼ��Ľṹ��
	{
		char Name[32];
		int Chinese_grade;
		int Math_grade;
		int English_grade;
	};
	
void init_info()										//�ļ��ж�ȡ����
{
	Student_grade = fopen("Student_grades.txt", "r");
	if(!Student_grade)
	{
		printf("�ļ� Student_grades.txt ��ʧ�ܣ�\n");
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
	
	printf("%s��ƽ���ɼ�Ϊ��%.2f\n",grades -> Name , mean_grade);
	
}

void change(int *x, int *y)								//�ȴ�С�󽻻�ֵ�ĺ���
{
	int temp = 0;
	temp = *x;
	*x = *y;
	*y = temp;
}

void low_grade(struct grade *grades)					//�ȴ�С�ĺ���
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

	printf("%s����ͷ���Ϊ%d\n\n", grades->Name, num1);
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
	init_info();										//�������г�ʼ���ĺ���
	float Chinese = 0;									//��������γ�ƽ���ɼ�
	float Math = 0;
	float English = 0;
	
	while(!feof(Student_grade))
	{
		int i = 0;
		i++;
		fscanf(Student_grade, "%s %d %d %d\n", grades[i].Name, &grades[i].Chinese_grade, &grades[i].Math_grade, &grades[i].English_grade);

		mean_grade(&grades[i]);								//��ȡƽ����
		
		low_grade(&grades[i]);								//��ȡ���ֵ	
		
		course_mean(&grades[i], &Chinese, &Math, &English);
	}
	
		printf("����ѧԱ���Ŀ�ƽ���ɼ�Ϊ��%.2f\n", Chinese / 4.00);
		printf("����ѧԱ��ѧ��ƽ���ɼ�Ϊ��%.2f\n", Math / 4.00);
		printf("����ѧԱ��Ӣ��ƽ���ɼ�Ϊ��%.2f\n\n", English / 4.00);

	return 0;
}















