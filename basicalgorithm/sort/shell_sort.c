#include <stdlib.h>
#include <stdio.h>

static void print(int *a, int first, int last)
{
    int i;
    for (i = first; i <= last; i++)
	printf("%d ", a[i]);
}

// shell排序是插入排序的一种改良和优化 
void shell_sort(int *a, int first, int last)
{
    int i, j, temp;
    int increment = last - first + 1;
    do 
    {
	increment = increment / 3 + 1;
	for (i = increment + first; i <= last; i += increment)   // 步长为increment的插入排序
	{							 // 特别注意i的初始值
	    temp = a[i];
	    j = i - increment;
	    while ((j >= first) && (a[j] > temp))
	    {
		a[j + increment] = a[j];
		j -= increment;
	    }
	    a[j + increment] = temp;
	}

    } while (increment > 1);
}

int main()
{
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    shell_sort(a, 0, 9);
    print(a, 0, 9);
    return 0;
}
