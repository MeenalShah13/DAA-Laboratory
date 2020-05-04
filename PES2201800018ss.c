#include<stdio.h>

int isSorted(int *a, int n)
{
int i;
for(i=0;i<(n-1);i++)
{
if(a[i]>a[i+1])
return 0;
}
return 1;
}

void swap(int *a,int *b)
{
int temp= *a;
*a=*b;
*b=temp;
}

void bubblePass(int *a, int n)
{
int i;
for(i=0;i<n-1;i++)
{
if(a[i]>a[i+1])
swap(&a[i],&a[i+1]);
}
}

void bubbleSort(int *a, int n)
{
while(!isSorted(a,n))
{
bubblePass(a,n);
}
}

int numBubblePasses(int *a, int n)
{
int c=0;
while(!isSorted(a,n))
{
bubblePass(a,n);
c++;
}
return c;
}

int maxIndex(int *a, int n)
{
int i,max=0;
for(i=1;i<n;i++)
{
if(a[i]>=a[max])
max=i;
}
return max;
}

void swapWithMax(int *a, int n)
{
int *temp,*am,*an;
int max=maxIndex(a,n);
if(max!=(n-1)&&max<(n-1))
{
am=&a[max];
an=&a[n-1];
temp=am;
am=&a[n-1];
an=temp;
}
}

void selectionSort(int *a, int n)
{
int i;
for(i=0;i<(n-1);i++)
{
if(isSorted(a,n))
return;
swapWithMax(a,n-i);
}
}

int numSwaps(int *a, int n)
{
int i,c=0;
for(i=0;i<(n-1);i++)
{
if(isSorted(a,n))
return c;
c++;
swapWithMax(a,n-i);
}
return c;
}
