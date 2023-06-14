#include<stdio.h>
double getmi(int a,int n);
int main()
{
	int n;
	scanf("%d",&n);
	int num=1,b=10;
	for(int i=0;i<n-1;i++){
		num*=10;
		b*=10;
	}
	
	int a;
	double sum=0;
	for(int i=num;i<b-1;i++){
		num=i;
		sum=0;
		for(int j=0;j<n;j++){
			a=num%10;
			num/=10;
			sum+=getmi(a,n);
		}
		if(sum==i*1.0){
			printf("%d\n",i);
		}
	}
	
	return 0;
}
double getmi(int a,int n)
{
	int temp=1;
	for(int i=0;i<n;i++){
		temp*=a;
	}
	return temp;
}
