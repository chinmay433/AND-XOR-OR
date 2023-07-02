#include<stdio.h>
#include<limits.h>
#define MAXN 1000000
int INT32_MIN,cur;
int max(int a,int b)
{
    return a>b?a:b;
}
int andxoror(int n,int* a)
{
    int stack[MAXN],top=-1;
    int result=INT32_MIN,cur;
    int i,temp;
    for(i=0;i<n;i++)
    {
        while(top>-1 && stack[top]>=a[i])
        {
            temp=stack[top--];
            result=max(result,temp^a[i]);
        }
        if(top>-1)
        {
            result=max(result,a[i]^stack[top]);
        }
        stack[++top]=a[i];
    }
    return result;
}
int main()
{
    int N,i,result;
    int a[MAXN];
    printf("Enter the value of N");
    scanf("%d", &N);
    printf("Enter the elements");
    for (int i = 0; i < N; ++ i) 
        scanf("%d", &a[i]);
    result=andxoror(N,a);
    printf("Maximum value of Si is %d",result);
    return 0;
}
