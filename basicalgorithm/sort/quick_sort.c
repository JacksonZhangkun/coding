#include <stdlib.h>
#include <stdio.h>

static void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

static void print(int *a, int low, int high)
{
    int i;
    for (i = low; i <= high; i++)
	printf("%d ", a[i]);
}

int partition(int *a, int low, int high)
{
    int pivotkey = a[low];  // 枢纽点
    int i = low;
    low++;

    while (low <= high)
    {
	while (low <= high && a[low] < pivotkey)
	    low++;
	while (low <= high && a[high] > pivotkey)
	    high--;
	if (low <= high)         // 这个地方千万要注意，一开始老是出错就是因为这里
	    swap(&a[low], &a[high]);
    }
    swap(&a[i], &a[high]);
    return high;
}

void quick_sort(int *a, int low, int high)
{
    int pivot;
    if (low < high)
    {
	pivot = partition(a, low, high);
	quick_sort(a, low, pivot - 1);
	quick_sort(a, pivot + 1, high);
    }
}
int main()
{
    int a[10] = {50,12,97,31,78,45,80,60,20,35};
    quick_sort(a, 0, 9);
    print(a, 0, 9);
    return 0;
}
