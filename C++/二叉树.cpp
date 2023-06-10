#include<stdio.h>
#include<malloc.h>
#define max 10
typedef struct bt{
	int data;
	struct bt *lchild,*rchild;
}Btree;

void Init(Btree *&a){
	a=(Btree*)malloc(sizeof(Btree));
	a->lchild=NULL;
	a->rchild=NULL;
}
int a[max];

void Create(Btree *&tree,int i,int n){
	Init(tree);
	tree->data=a[i];
	if(2*i+1<=n){
		Create(tree->lchild,2*i,n);
		Create(tree->rchild,2*i+1,n);
	}
}
void levelOrder(Btree* root) {//层序输出
	if (root == NULL) {
		return;
	}
	//定义队列和辅助指针
	Btree **queue = (Btree**)malloc(sizeof(Btree*)*1000);
	int front = 0, rear = 0;
	queue[rear++] = root;
	
	while (front != rear) {
		Btree *cur = queue[front++];
		printf("%d ", cur->data);
		if (cur->lchild != NULL) 
			queue[rear++] = cur->lchild;
		if (cur->rchild != NULL) 
			queue[rear++] = cur->rchild;
	}
	free(queue);
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	Btree *tree;
	Create(tree,1,n+1);
	printf("层序输出结果为：\n");
	levelOrder(tree);
	return 0;
}
