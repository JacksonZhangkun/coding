#include <stdlib.h>
#include <stdio.h>

// 选择排序 是冒泡和插排的结合
void select_sort(int *a, int first, int last)
{
    int i, j, min, temp;

    for (i = first; i <= last; i++)
    {
	min = i;             // 用 i 初始化最小元素下标

	for (j = i + 1; j <= last; j++)
	    if (a[j] < a[min])
		min = j;
	
	if (min != i)        // 发现最小元素变化, 要交换
	{
	    temp = a[i];
	    a[i] = a[min];
	    a[min] = temp;
	}
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
    select_sort(a, 0, 9);
    print(a, 0, 9);
    return 0;
}
