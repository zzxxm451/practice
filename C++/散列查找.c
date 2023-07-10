#include<stdio.h>
int a[18];
int Hask(int k){
	int m=k;
	while(m>=17)
		m%=17;
	return m;
}
int Input(int k){
	int m=Hask(k);
	if(a[m]==-1)
		return m;
	int count=1;
	while(1){
		if(a[count*count+m]==-1){
			return count*count+m;
		}else
			count++;
	}
}

void Search(int b){
	int m=Hask(b);
	if(a[m]==-1){
		printf("%d not found,try 1\n",b);
		return;
	}
	int count=1;
	if(a[m]==b){
		printf("%d pos:%d,try %d\n",b,m,count);
		return;
	}
	
	//count++;
	int tem=count*count+m;
	count++;
	while(tem<18){
        if(a[tem]==-1){
		    printf("%d not found,try %d\n",b,count);
		    return;
	    }
		if(a[tem]==b){
			printf("%d pos:%d,try %d\n",b,tem,count);
			return;
		}else{
			
			tem=count*count+m;
			count++;
		}	
	}
	printf("%d not found,try %d\n",b,count-1);
}

int main()
{
	for(int i=0;i<18;i++)
		a[i]=-1;
	int num1;
	scanf("%d",&num1);
	int num[num1];
	for(int i=0;i<num1;i++){
		scanf("%d",&num[i]);
		int tep=Input(num[i]);
		a[tep]=num[i];
		printf("%d ",tep);
	}
	printf("\n");
	//测试
	/*for(int i=0;i<18;i++){
		printf("%d ",a[i]);
	}*/	
	int num2;
	scanf("%d",&num2);
	int b[num2];
	
	for(int i=0;i<num2;i++){
		scanf("%d",&b[i]);
		Search(b[i]);
	}
	return 0;
}
