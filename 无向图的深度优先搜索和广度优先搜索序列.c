#include<stdio.h>
#define Max 70
typedef struct {
	int v,e;
	int arc[Max][Max];
}Graph;

int visited[Max];
int Sum(int visited[],int n){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=visited[i];
	}
	return sum;
}
void DFS(Graph g,int begin){
	visited[begin] = 1;
	printf("%d ",begin); 
	for(int j=1;j<=g.v;j++){
		if(g.arc[begin][j] == 1 && !visited[j])
			DFS(g,j);  //对未访问的邻接顶点的递归 
	}
}

typedef struct{
	int data[Max];
	int front;
	int rear;
}queue;
void Init(queue &q){
	q.front=-1;
	q.rear=-1;
	for(int i=0;i<Max;i++){
		q.data[i]=-1;
	}
}
void Push(queue &q,int a){
	q.data[++q.rear]=a;
}
int Pop(queue &q){
	return q.data[++q.front];
}
int main()
{
	Graph g;int begin;
	scanf("%d %d %d",&g.v,&g.e,&begin);
	for(int i=1;i<=g.v;i++)
		visited[i]=0;
	
	for(int i=1;i<=g.v;i++){
		for(int j=1;j<=g.v;j++)
			g.arc[i][j]=0;
	}
	int a,b;
	for(int i=1;i<=g.e;i++){
		scanf("%d %d",&a,&b);
		g.arc[a][b]=1;g.arc[b][a]=1;
	}

	DFS(g,begin);
	printf("\n");
	for(int i=1;i<=g.v;i++)
		visited[i]=0;
	
	int x=begin;printf("%d ",x);visited[x]=1;
	queue q;
	Init(q);
	
	while(1){//广度优先
		if(Sum(visited,g.v)==g.v){
			break;
		}
		for(int i=1;i<=g.v;i++){
			if(g.arc[x][i]==1&&visited[i]==0){
				printf("%d ",i);visited[i]=1;
				Push(q,i);
			}
		}
		x=Pop(q);
	}
	
	return 0;
}
/*
#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 11;
int G[MAXN][MAXN];
bool visited[MAXN] = {false};

// 深度优先搜索
void DFS(int u, int N) {
    visited[u] = true;
    cout << u << " ";
    for (int v = 1; v <= N; v++) {
        if (!visited[v] && G[u][v]) DFS(v, N);
    }
}

// 广度优先搜索
void BFS(int u, int N) {
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cout << t << " ";
        for (int v = 1; v <= N; v++) {
            if (!visited[v] && G[t][v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    // 读入数据
    int N, M, S;
    cin >> N >> M >> S;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1; // 标记无向图的边
    }
    
    // 深度优先搜索
    DFS(S, N);
    cout << endl;
    
    // 广度优先搜索
    fill(visited + 1, visited + N + 1, false); // 重新初始化访问数组
    BFS(S, N);
    cout << endl;
    return 0;
}
*/
/*构造一个无向图，从给定起点开始进行深度优先遍历和广度优先遍历，并输出相应的遍历序列。

输入格式:
输入第一行给出三个正整数，分别表示无向图的节点数N（1<N≤10）、边数M（≤50）和遍历的起始节点编号S（节点从1到N编号）。

随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个节点的编号。

输出格式:
输出包括两行。
第一行从S开始的无向图的深度优先搜索序列，中间用空格隔开，行末可有空格；
第二行从S开始的无向图的广度优先搜索序列，中间用空格隔开，行末可有空格。

注：为了保证输出序列的唯一性，在遍历时先从相邻节点中编号小的节点开始（在没有重复访问的情况）。*/
