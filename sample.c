#include<stdio.h>

void swap(int *a,int *b)
{
int temp= *a;
*a=*b;
*b=temp;
}

void bubbleSort(int *a,int n)
{
int j,i;
for(j=0;j<(n-1);j++)
{
for(i=0;i<n-1;i++)
{
if(a[i]>a[i+1])
swap(&a[i],&a[i+1]);
}
}
}

int main()
{
int n,i;
printf("Enter the number of elements:");
scanf("%d",&n);
int a[n];
printf("Enter the elements:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("\nSorted elements are:\n");
bubbleSort(a,n);
for(i=0;i<n;i++)
{
printf("%d ",a[i]);
}
printf("\n");
return 0;
}
