#include<stdio.h>
#include<conio.h>
#define MAX 20
int array [MAX];
void merge (int low, int mid, int high) {
	int temp[MAX];
	int i = low;
	int j = mid+1;
	int k = low;
	while((i<=mid) && (j<=high)) {
		if (array[i] <= array[j])
			temp[k++] = array [i++];
		else
			temp[k++] =array[j++];
	}
	while(i <=mid)
		temp[k++] = array[i++];
	while(j<= high)
		temp[k++] = array[j++];
	for (i = low; i < high; i++)
	{
		array[i]=temp[i];
	}
}
void merge_sort(int low, int high) {
	int mid;
	if (low != high)
	{
		mid = (low +high)/2;
		merge_sort(low,mid);
		merge_sort(mid +1, high);
		merge(low,mid,high);
	}
}
int main() {
	int i , n;
	printf("Enter the number of elements : \n");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter element %d : \n",i+1 );
		scanf("%d", &array[i]) ;
	}
	printf("Unsorted list is: \n");
	for (i = 0; i < n; i++)
	{
		printf("%d", array[i] );
		
	}
	merge_sort(0,n-1);
	printf("Sorted list is : \n");
	for (i = 0; i < n; i++)
	{
		printf("%d", array[i] );
		
	}
	return 0;
}
