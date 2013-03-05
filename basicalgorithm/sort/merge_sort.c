#include <stdlib.h>
#include <stdio.h>

static void print(int *a, int first, int last)
{
    int i;
    for (i = first; i <= last; i++)
	printf("%d ", a[i]);
}

void merge(int *a, int lower, int mid, int high)
{
    int i = lower;
    int j = mid + 1;

    int temp[high - lower + 1];
    int k = 0;
    
    while (i <= mid && j <= high)
    {
	if (a[i] < a[j])
	    temp[k++] = a[i++];
	else
	    temp[k++] = a[j++];
    }
    if (i == mid + 1)
    {
	while (j <= high)
	    temp[k++] = a[j++];
    }
    else
    {
	while (i <= mid)
	    temp[k++] = a[i++];
    }

    for (i = lower, k = 0; i <= high; i++, k++)
	a[i] = temp[k];
}

void merge_sort(int *a, int first, int last)
{
    if (first < last)
    {
	int mid = (first + last) / 2;
	merge_sort(a, first, mid);
	merge_sort(a, mid + 1, last);
	merge(a, first, mid, last);
    }
}

int main()
{
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    merge_sort(a, 0, 9);
    print(a, 0, 9);
    return 0;
}
