#include<stdio.h>
int main ()
{
	int score;
	char grade;
	printf("please input score:\n");
	scanf("%d",&score);
	/*if (score<=100&&90<=score)
	{
		grade = 'A';
	}
	if (score<90&&80<=score)
	{
		grade = 'B';
	}
	if (score<80&&70<=score)
	{
		grade = 'C';
	}
	if (score<70&&60<=score)
	{
		grade = 'D';
	}
	if (score<60)
	{
		grade = 'E';
	}
	if(score<0||score>100)
	{
		printf("input errpr!");
	}
	else printf("grade = %c",grade);*/
	if (score>100||score<0)
	{
		printf("input error");
	}
	else
	{
		if (score>=90) grade = 'A';
		else if (score>=80) grade = 'B';
		else if (score>=70) grade = 'C';
		else if (score>=60) grade = 'D';
		else grade = 'E';
		printf("grade = %c",grade);
	}
	return 0;
}
