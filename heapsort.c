#include<stdio.h>


void max_heap(int arr[], int i, int n)
{
	int left = 2*i;
	int temp;
	int right = 2*i + 1;
	int largest = i;
	if(left <= n && arr[left] > arr[i])
		largest = left;
	if(right <= n && arr[right] > arr[largest])
		largest = right;
	if(largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		max_heap(arr, largest, n);
	}
	return ;
}



void heap(int arr[], int n)
{
	int i;
	for(i=n/2 ;i>=1 ;i--)
		max_heap(arr, i, n);
}



void heap_sort(int arr[], int n)
{
	int heap_size = n;
	heap(arr, heap_size);
	int i, temp;
	for(i=n;i>=2;i--)
	{
		//printf("%d ",arr[1]);
		temp = arr[1];
		arr[1] = arr[i];
		arr[i] = temp;
		heap_size -= 1;
		max_heap(arr,1,heap_size);
	}
}



int main()
{
	int arr[1000];
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&arr[i]);
	heap_sort(arr, n);
	//printf("%d\n",arr[1]);
	for(i=1;i<=n;i++)
        printf("%d \n",arr[i]);
	return 0;
}

