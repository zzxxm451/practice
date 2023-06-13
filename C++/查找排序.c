#include <stdio.h>
#include<string.h>
#define max 11
typedef struct likes{
	int num;
	char uname[max];
}Like;

int main(){
	int n;
	scanf("%d",&n);
	Like a[n];
	for(int i=0;i<n;i++){//方便后续按人名查找
		for(int j=0;j<max;j++)
			a[i].uname[j]='\0';
	}
	for(int i=0;i<n;i++)
		scanf("%s %d",a[i].uname,&a[i].num);
	char s[max];
	for(int i=0;i<max;i++)
		s[i]='\0';
	scanf("%s",s);
	Like tmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i].num>a[j].num){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
	printf("输出结果：\n");
	for(int i=0;i<n;i++){
		printf("%s %d  ",a[i].uname,a[i].num);
	}
	printf("\n");
	int flag=1;
	for(int i=0;i<n;i++){
		if(strcmp(s,a[i].uname)==0){
			printf("The range of %s is %d",a[i].uname,i+1);
			flag=0;
			break;
		}
	}
	if(flag){
		printf("no %s",s);
	}
	return 0;
}
/*
一些社交媒体会提供点赞排行榜的功能，比如微博、抖音等，用户可以在这些社交媒体上查看点赞排行榜。现以微博上的某些用户的点赞数据为例，编写程序完成点赞排行榜的输出，并查找某个用户在点赞排行榜的排名。
其中点赞数据包括用户名和点赞数，用户名位不超过10个字符的字符串。
输入为一个整数n，随后是n个用户的点赞数据，再输入一个用户名name，请输出这n个用户的点赞排行榜，以及name这个用户的排名。

*/
