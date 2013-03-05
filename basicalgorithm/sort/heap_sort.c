#include <stdlib.h>
#include <stdio.h>

static void print(int *a, int first, int last)
{
    int i;
    for (i = first; i <= last; i++)
	printf("%d ", a[i]);
}

static void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

static void heap_adjust(int *a, int first, int last)     // 建立堆
{
    int i = first + (last - first) / 2;
    for (;i >= 0; i--)
    {
	if ((2 * i + 2 <= last) && (a[2 * i + 1] > a[2 * i + 2]))
	    if (a[i] < a[2 * i +1])
		swap(&a[i], &a[2 * i + 1]);

	if ((2 * i + 2 <= last) && (a[2 * i + 1] < a[2 * i + 2]))
	    if (a[i] < a[2 * i + 2])
		swap(&a[i], &a[2 * i + 2]);
    }
}

void heap_sort(int *a, int first, int last)
{
    int i;
    for (i = last; i >= first; i--)
    {
	heap_adjust(a, first, i);
	swap(&a[first], &a[i]);
    }
}

int main()
{
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    heap_sort(a, 0, 9);
    print(a, 0, 9);
    return 0;
}
