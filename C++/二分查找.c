#include<stdio.h>

int Search(int a[],int key,int n){
	int head=0,end=n-1,mid;
	while(head<=end){
		mid=(head+end)/2;
		if(a[mid]==key)
			return mid+1;
		if(a[mid]<key){
			head=mid+1;
		}else
			end=mid-1;
	}
	return -1;
}

int main()
{
	int k;
	int n,key;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %d",&n,&key);
		int a[n];
		for(int j=0;j<n;j++)
			scanf("%d",&a[j]);
		
		int index=Search(a,key,n);
		printf("%d",index);
		if(i!=k-1)
			printf("\n");
	}
	
	return 0;
}
