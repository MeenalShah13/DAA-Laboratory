#include<stdio.h>

void mergeSortedHalfs(int *a, int start, int mid, int end)
{
	int n1=mid-start+1,n2=end-mid,i=0,j=0,k=start;
	int t1[n1],t2[n2];
	
	for(i=0;i<n1;i++)
		t1[i]=a[start+i];
	for(i=0;i<n2;i++)
		t2[i]=a[mid+1+i];

	i=0;
	
	while(i<n1&&j<n2)
	{
		if(t1[i]<t2[j])
		{
			a[k]=t1[i];
			i++;
		}
		else
		{
			a[k]=t2[j];
			j++;
		}
		k++;
	}
	while(j<n2)
	{
		a[k]=t2[j];
		j++;
		k++;
	}
	while(i<n1)
	{
		a[k]=t1[i];
		i++;
		k++;
	}
}

void mergeSort(int *a, int start, int end)
{
	if(start<end&&start>=0)
	{
		int mid=start+((end-start)/2);
		mergeSort(a,start,mid);
		mergeSort(a,mid+1,end);

		mergeSortedHalfs(a,start,mid,end);
	}
}

void insertionSort(int *a, int start, int end)
{
	int i,j;    
	for(i=0;i<=end;i++){
        int temp = a[i];
        j = i-1;
        
        while (j>=0 && a[j] > temp)
        {   
            a[j+1] = a[j];
            j--;
        }
        
        a[j+1] = temp;
        
    }
}

void selectiveMergeSort(int *a, int start, int end, int parameter)
{
	if(end+1>parameter)
		mergeSort(a,start,end);
	else
		insertionSort(a,start,end);
}
