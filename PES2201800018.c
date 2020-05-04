#include<stdio.h>
#include"session12_WarshallsFloyds.h"
#include <stdlib.h>
#include <time.h>
#include<string.h>

double time_elapsed(struct timespec start, struct timespec end) {
    double t;
    t = (end.tv_sec - start.tv_sec); 
    t += (end.tv_nsec - start.tv_nsec) * 0.000000001;
    return t*1000;
}

int min(int x, int y)
{
	return (x > y)? y : x;
}

void transitive_closure_warshalls(int **g, int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				g[i][j]=g[i][j] || (g[i][k] && g[k][j]);
			}
		}
	}
}

void all_pairs_shortest_path_distances_floyds(int **g, int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				g[i][j]= min(g[i][j],(g[i][k]+g[k][j]));
			}
		}
	}
}

int main()
{
	struct timespec start, end;
	int n,i,j;
	scanf("%d",&n);
	int **g=(int **)calloc(n,sizeof(int *));
	for(i=0;i<n;i++)
	{
		g[i]=(int *)calloc(n,sizeof(int));
	}
	for(i=0;i<n;i++)
	{
        	for(j=0;j<n;j++)
		{
			scanf("%d",&g[i][j]);
		}
	}
	scanf("%d",&n);
	int **a=(int **)calloc(n,sizeof(int *));
	for(i=0;i<n;i++)
	{
		a[i]=(int *)calloc(n,sizeof(int));
	}
	for(i=0;i<n;i++)
	{
        	for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	clock_gettime(CLOCK_REALTIME, &start);
	transitive_closure_warshalls(g, n);
	clock_gettime(CLOCK_REALTIME, &end);
	printf("Warshall's Algorithm execution time: %lf\n", time_elapsed(start, end));
	for(i=0;i<n;i++)
	{
        	for(j=0;j<n;j++)
		{
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	clock_gettime(CLOCK_REALTIME, &start);
	all_pairs_shortest_path_distances_floyds(a, n);
	clock_gettime(CLOCK_REALTIME, &end);
	printf("Floyd's Algorithm execution time: %lf\n", time_elapsed(start, end));
	for(i=0;i<n;i++)
	{
        	for(j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	return 0;
}