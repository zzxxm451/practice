#include<stdio.h>
#include<string.h>

#include<iostream>
using namespace std;
#define Max 50

typedef struct{
	int top;
	char a[Max];
}Sqstack;

void Init(Sqstack &str){
	str.top=-1;
	for(int i=0;i<Max;i++){
		str.a[i]='\0';
	}
}

void Pop(Sqstack &str){
/*	do{
		str.top++;
        //printf("%d\n",str.top);
		scanf("%c",&(str.a[str.top]));printf("%c,%d",(str.a[str.top]),str.top);
	}while(str.a[str.top]!='\n'); //防止栈溢出
    str.a[str.top]='\0';*/
    
    //str.top--;
    cin.getline(str.a,Max,'\n');
    str.top=strlen(str.a)-1;
    //printf("%s %d\n",str.a,str.top);
}

void Push(Sqstack &str1,Sqstack &str2){
	for(int i=0;i<=str1.top;i++){ 
		str2.a[i]=str1.a[str1.top-i];
		printf("%c",str1.a[i]);
	}
	str2.top=str1.top;
}

int main(){
	Sqstack str;
	Init(str);
	Pop(str);
	Sqstack str1;
	Init(str1);
	Push(str,str1);
	int flag=1;
	for(int i=0;i<str.top;i++){
		if(str.a[i]==str1.a[i]){
			continue;
		}else{
			flag=0;
			break;
		}
	}
	if(flag){
        printf("是回文。");
    }else{
        printf("不是回文。");
    }
	return 0;
}
/*
回文是指正读反读均相同的字符序列，如“abba”和“abdba”均是回文，但“good”不是回文。试写一个程序判定给定的字符向量是否为回文，用栈实现。(提示：将一半字符入栈)
*/
