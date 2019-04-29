#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 6
void QuickSort(int arr[],int l,int r)
{
    if (l>=r)
    {
        return;
    }
    int i = l;
    int j = r;
    int v = arr[i];
    while (i<j)
    {
        while (i<j&&arr[j]>=v)
        {
            j--;
        }
        arr[i] = arr[j];
        while (i< j&&arr[i]<=v)
        {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = v;
    QuickSort(arr,l,i-1);
    QuickSort(arr,i+1,r);

}
void main()
{
	int n = N;
	int arr[N];
	int i;
	srand(time(0));//用系统时间作为随机数种子
	for (i=0; i<N; i++)
		//arr[i]=1000*rand()/RAND_MAX; //0-1000以内的随机整数
		scanf("%d", &arr[i]);
	printf("排序前:\n");
	for (i = 0; i < n; i++)
    {
       printf("%5d",arr[i]);
    }
	printf("\n");
	QuickSort(arr,0,n-1);
	printf("排序后:\n");
    for (i = 0; i < n; i++)
    {
       printf("%5d",arr[i]);
    }
	printf("\n");
}