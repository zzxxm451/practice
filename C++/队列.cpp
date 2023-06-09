#include<stdio.h>
#define max 10
typedef struct que{
	int a[max];
	int front;
	int rear;
	int num;//作业个数
}queue;

bool IsFull(queue que){
	return (que.rear+1)%max==que.front;
}
bool IsEmpty(queue que){
	return que.num==0;
}
void Init(queue &que){
	for(int i=0;i<max;i++)
		que.a[i]=0;
	que.front=0;
	que.rear=0;
	que.num=0;
}

void Push(queue &que,int time){
	if(IsFull(que))
		return;
	if(IsEmpty(que)){
		que.a[que.rear++]=time;//尾插
		return;
	}
	int ave=(que.a[que.front]+que.a[que.rear-1])/2;
	if(time>=ave){
		que.a[que.rear++]=time;//尾插
		return;
	}else{
		que.front=(que.front-1+max)%max;//头插
		que.a[que.front]=time;
		return;
	}
}

int main(){
	queue que;
	Init(que);
	int n;
	printf("请输入作业个数：\n");
	scanf("%d",&n);//作业个数
	int time;
	printf("请输入每次作业预计时间：\n");
	for(int i=0;i<n;i++){
		scanf("%d",&time);
		Push(que,time);
		que.num++;
	}
	printf("经过排序后：\n");
	for(int i=0;i<n;i++){
		printf("%d ",que.a[(que.front++)%max]);
	}
	
	return 0;
}
/*采用顺序存储结构，实现输出受限的双端循环队列的入列和出列算法（只允许队头出列）。
设每个元素表示一个作业的预计执行时间。入队列时采取简化的短作业优先原则，若新入队的作业的预计执行时间小于队头和队尾作业的平均执行时间，则插入在队头，否则插入在队尾。
*/
