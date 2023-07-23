#include<stdio.h>

void Hanoi(int n,char a,char b,char c){
    if(n==1)
        printf("%c -> %c\n",a,c);
    else{
        Hanoi(n-1,a,c,b);
        printf("%c -> %c\n",a,c);
        Hanoi(n-1,b,a,c);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    char a='a',b='b',c='c';
    Hanoi(n,a,b,c);
}
