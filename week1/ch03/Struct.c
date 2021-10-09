#include<stdio.h>
#include<string.h>
/*结构体：
使得多个不同类型，但具有逻辑相关的变量放到一起存储*/
int main ()
{
	struct student//申明一个结构体类型叫student 
	{
		long studentid;
		char studentName[10];
		char studentSex;
		int score[3]; 
	};
	//其中包含4个不同类型变量，分别具有不同含义
	/*typedef struct student STUDENT
	这个语句可以将使得：
	STUDENT是struct student在后面的语句中互换*/ 
	struct student a={2019001,"狂徒张三",'M',{60,61,62}};
	//申明一个student结构体类型的变量叫做a 
	printf("%d\n",a.studentid);
	printf("%s",a.studentName);
	struct student b;
	b.studentid = 2019002;
	/*结构体访问方式要
	结构体名称.结构内的变量名*/
	strcpy(b.studentName,"李四"); 
	/*字符串不能直接赋值
	要使用strcpy函数，在<string.h>库中*/ 
}
