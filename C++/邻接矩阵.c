#include<stdio.h>

int main()
{
	int n,e;
	scanf("%d %d",&n,&e);
	int edges[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			edges[i][j]=0;
		}
	}
	char str[100];
	for(int i=0;i<=n+1;i++){
		str[i]=getchar();
	}
	//getchar();
	/*char a='A';
	  int b = (int)a-65;*/
	char a,b;
	for(int i=0;i<e;i++){
		a=getchar();b=getchar();getchar();
		int A=(int)a-65;int B=(int)b-65;
		edges[A][B]=1;edges[B][A]=1;
	}/*
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",edges[i][j]);
		}
		printf("\n");
	}*/
	int i=0;
	for(i=0;i<n;i++){
		int num=0;
			for(int j=0;j<n;j++){
				num+=edges[i][j];
			}
		printf("%d",num);
		if(i<n-1){
			printf(" ");
		}
	}
	return 0;
}
/*采用邻接矩阵表示法创建无向图G ，依次输出各顶点的度。

输入格式:
输入第一行中给出2个整数i(0<i≤10)，j(j≥0)，分别为图G的顶点数和边数。
输入第二行为顶点的信息，每个顶点只能用一个字符表示。
依次输入j行，每行输入一条边依附的顶点。

输出格式:
依次输出各顶点的度，行末没有最后的空格。*/
