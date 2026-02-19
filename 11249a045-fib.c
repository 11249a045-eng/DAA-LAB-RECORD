#include<stdio.h>
int main()
{
    int t1=0,t2=1,i,n,next;
    printf("enter number of terms: ");
    scanf("%d",&n);
    printf("Fibonacci series:%d%d",t1,t2);
    for(i=3;i<n;i++){
        next=t1+t2;
        printf("%d",next);
        t1=t2;
        t2=next;
    }
    return 0;
}
