#include <stdio.h>
#include<malloc.h>

typedef struct student{
	int num;
	int point;
	char uname;
	student *next;
}stu;

void Init(stu *&A){
	A=(stu*)malloc(sizeof(stu));
	A->next=NULL;
}

int main(){
	int a,b;//A，B班级人数
	printf("请输入A，B班人数：\n");
	scanf("%d %d",&a,&b);
	stu *A;//A的头节点
	Init(A);
	stu *C;//A的第一个数据
	Init(C);
	A->next=C;
	printf("请输入A班学生信息：\n");
	scanf("%d %d %s",&C->num,&C->point,&C->uname);
	for(int i=1;i<a;i++){
		stu *tem;
		Init(tem);
		scanf("%d %d %s",&tem->num,&tem->point,&tem->uname);
		C->next=tem;
		C=C->next;
	}

	stu *B;
	Init(B);
	Init(C);
	B->next=C;
	printf("请输入B班学生信息：\n");
	scanf("%d %d %s",&C->num,&C->point,&C->uname);
	for(int i=1;i<a;i++){
		stu *tem;
		Init(tem);
		scanf("%d %d %s",&tem->num,&tem->point,&tem->uname);	
		C->next=tem;
		C=C->next;
	}
	
	int num1,len,num2;
	printf("请输入第几号开始有几个学生转到B班以及安排在第几号之前\n");
	scanf("%d %d %d",&num1,&len,&num2);
	stu *tmp1;
	Init(tmp1);
	tmp1=A;
	for(int i=0;i<num1-1;i++){
		tmp1=tmp1->next;
	}
	stu *tmp2;
	Init(tmp2);
	tmp2=tmp1;
	for(int i=0;i<len;i++){
		tmp2=tmp2->next;
	}//tmp2未换班
	
	stu *tmp3;
	Init(tmp3);
	tmp3=B;
	for(int i=0;i<num2-1;i++){
		tmp3=tmp3->next;
	}

	stu *tmp;
	Init(tmp);
	tmp=tmp2->next;
	tmp2->next=tmp3->next;
	tmp3->next=tmp1->next;
	tmp1->next=tmp;
	A=A->next;
	printf("A班学生信息：\n");
	while(A){
		printf("%d %d %c\n",A->num,A->point,A->uname);
		A=A->next;
	}
	printf("\n");
	B=B->next;
	printf("B班学生信息：\n");
	while(B){
		printf("%d %d %c\n",B->num,B->point,B->uname);
		B=B->next;
	}
	
	return 0;
}
/*现有A、B两个班级的学生，学生的信息包括学号、姓名、成绩，将这两个班级的学生按照学号顺序分别保存在两个单链表中（学号从1开始编号）。
期末时经过转专业考试后，A班从i号开始有len个学生转专业考试通过，转到B班级，转到B班级后，将这len个学生安排在B班的j号学生之前。
请编写程序，先输入A、B班级的学生信息，再输入i，len和j的值，最后输出转专业后，A、B班的学生信息（按照顺序输出）。
*/
