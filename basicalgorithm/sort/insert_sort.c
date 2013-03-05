#include <stdlib.h>
#include <stdio.h>

void insert_sort(int *a, int first, int last)
{
    int i, j;
    int temp;

    for (i = first + 1; i <= last; i++ )
    {
	temp = a[i];    // 作为新要插到数组中的值
	j = i - 1;      // 已排好序列的最后一个元素的下标

	while ((j >= first) && (a[j] > temp))    // 比新要插的数大，那么后退 直到遇到小的为止
	{
	    a[j + 1] = a[j];
	    j--;
	}
	a[j + 1] = temp;
    }
}

static void print(int *a, int first, int last)
{
    int i;
    for (i = first; i <= last; i++)
	printf("%d ", a[i]);
}

int main()
{
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    insert_sort(a, 0, 9);
    print(a, 0, 9);
    return 0;
}
