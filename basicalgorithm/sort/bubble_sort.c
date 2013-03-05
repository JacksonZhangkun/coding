#include <stdlib.h>
#include <stdio.h>

static void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort1(int *a, int N)
{
    int i, j;
    for (i = 0; i < N - 1; i++)
	for (j = i + 1; j < N; j++)
	    if (a[i] > a[j])
		swap(&a[i], &a[j]);
}

//update 冒泡排序
void bubble_sort2(int *a, int N)
{
    int i, j;
    unsigned char flag = 1;
    for (i = 0; i < N - 1 && flag; i++)
    {
	flag = 0;
	for (j = i + 1; j < N; j++)
	    if (a[i] > a[j])
	    {
		swap(&a[i], &a[j]);
		flag = 1;                 //如果没有交换，则整个数列已经排好序
	    }
    }
}

static void print(int *a, int N)
{
    int i;
    for (i = 0; i < N; i++)
	printf("%d ", a[i]);
}
int main()
{
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    bubble_sort2(a, 10);
    print(a, 10);
    return 0;
}
