#include <stdio.h>
int andxoror(int a[], int n)
{
    int i,j,smallest,secondsmallest,si,maxsi=0;
    for(i = 0; i<n-1; i++)
    {
        if(a[i]<a[i+1])
        {
            smallest = a[i];
            secondsmallest = a[i+1];
        }
        else
        {
            smallest = a[i+1];
            secondsmallest = a[i];
        }
        for(j = i+1; j<n; j++)
        {
            if(a[j] < smallest)
            {
                secondsmallest = smallest;
                smallest = a[j];
            }
            else if(a[j] < secondsmallest && a[j] != smallest)
            {
                secondsmallest = a[j];
            }
            si = (((smallest&secondsmallest)^(smallest|secondsmallest))&(smallest^secondsmallest));
            if(si>maxsi)
            maxsi = si;
        }
    }
    return maxsi;
}
int main()
{
    int a[100],n,i,maxsi,si;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for( i = 0; i<n; i++)
        scanf("%d",&a[i]);
    maxsi = andxoror(a,n);
    printf("Maximum value of Si is %d\n",maxsi);
}