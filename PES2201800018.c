#include "session5_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>

double time_elapsed(struct timespec start, struct timespec end) {
    double t;
    t = (end.tv_sec - start.tv_sec); 
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001;
    return t*1000;
}

long int InsertionSort(Record* A,int n){
    long int count = 0,i,j;
    for(i=1;i<n;i++){
        Record temp = A[i];
        j = i-1;
        
        while (j>=0 &&(++count)&& A[j].serialnumber > temp.serialnumber)
        {   
            A[j+1] = A[j];
            j--;
        }
        
        A[j+1] = temp;
        
    }
    return count;
}

long int BubbleSort(Record* A,int n){
    int flag = 1;
    long int count = 1,i,j;
    for(i = 1;i<n;i++){
        flag =1;
        for(j=0;j<i;j++){
            count++;
            if(A[j].serialnumber > A[j+1].serialnumber){
                Record temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 0;
            }
        }
        
    }
    return count;
}

long int SelectionSort(Record* A, int n){
    long int count = 0,i,j;
    for(i=0;i<n-1;i++){
        int min = i;
        for(j=i+1;j<n;j++){
            if(A[j].serialnumber < A[min].serialnumber){
                Record temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
        count+=n-i-1;

    }
    return count;
}


int main()
{
    struct timespec start, end;

    long int n,i,count;
    char c;
    scanf("%ld",&n);
    Record* A = (Record*)calloc(n,sizeof(Record));
    for(i=0;i<n;i++)
    {
        scanf("%ld %d",&A[i].serialnumber,&A[i].score);
    }
    clock_gettime(CLOCK_REALTIME, &start);
    count = InsertionSort(A,n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Insertion Sort count: %ld\n",count);
    printf("Insertion sort time: %lf\n", time_elapsed(start, end));

    clock_gettime(CLOCK_REALTIME, &start);
    count = BubbleSort(A,n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Bubble Sort count: %ld\n",count);
    printf("Bubble Sort time: %lf\n", time_elapsed(start, end));
   
    clock_gettime(CLOCK_REALTIME, &start);
    count = SelectionSort(A,n);
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Selection Sort count: %ld\n",count);
    printf("Selection Sort time: %lf\n", time_elapsed(start, end));
    
    getchar();getchar();getchar(); 
    return 0;

}
