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
/*
已知一棵完全二叉树存于顺序表sa中，sa.elem[1]~sa.elem[last]存储结点的值。试编写算法由此顺序存储结构建立该二叉树的二叉链表。
解题思路：根据完全二叉树顺序存储的性质来确定二叉树的父子关系即“还原”了二叉树，之后再按照二叉树二叉链表的构造方法进行建立。完全二叉树顺序存储的一个重要性质为，第i个结点的左孩子是编号为2i的结点，第i个结点的右孩子是编号为2i+1的结点。

*/
