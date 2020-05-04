#include<stdio.h>

typedef struct Record {
	long int serialnumber;
	int score;
} Record;

long int InsertionSort(Record* A, int n)
{
long int c=0;
Record key;
int j;
for(int i=1;i<n;i++)
{
key=A[i];
j=i-1;
while (j>=0&&A[j].serialnumber>key.serialnumber) 
{
c++;
A[j+1]=A[j];  
j=j-1;  
}  
A[j+1]=key;
}
return c;
}

long int BubbleSort(Record* A, int n)
{
long int c=0;
Record temp;
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++)
{
c++;
if(A[j].serialnumber>A[j+1].serialnumber)
{
temp=A[j];
A[j]=A[j+1];
A[j+1]=temp;
}
}
}
return c;
}

long int SelectionSort(Record* A, int n)
{
long int c=0;
int min;
Record temp;
for(int i=0;i<n-1;i++)
{
min=i;
for(int j=i;j<n;j++)
{
c++;
if(A[min].serialnumber>A[j].serialnumber)
min=j;
}
temp=A[min];
A[min]=A[i];
A[i]=temp;
}
return c;
}

int main()
{
Record a={123456789,100};
Record b={222222222,200};
Record c={111111111,300};
Record A[3]={a,b,c};
printf("Insertion Sort: %ld\n",InsertionSort(A,3));
printf("A:%ld %ld %ld\n",A[0].serialnumber,A[1].serialnumber,A[2].serialnumber);
//A[3]={a,b,c};
printf("Bubble Sort: %ld\n",BubbleSort(A,3));
printf("A:%ld %ld %ld\n",A[0].serialnumber,A[1].serialnumber,A[2].serialnumber);
//A[3]={a,b,c};
printf("Selection Sort: %ld\n",SelectionSort(A,3));
printf("A:%ld %ld %ld\n",A[0].serialnumber,A[1].serialnumber,A[2].serialnumber);
return 0;
}
