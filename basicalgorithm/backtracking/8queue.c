#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#define QUEEN 8
int a[QUEEN] = {INT_MIN};

int valid(int row, int col)           // 判断第row行 第col列是否可以防止皇后
{
    int i;
    for (i = 0; i < QUEEN; i++)       // 对棋盘进行扫描
    {
	if (a[i] == col || abs(i - row) == abs(a[i] - col))  //判断列冲突与斜线上的冲突
	    return 0;
    }
    return 1;
}

void init()     // 初始化
{
    int i;
    for (i = 0; i < QUEEN; i++)
	a[i] = INT_MIN;
}
void print()    // 输出N皇后的一组解
{
    int i, j;
    for (i = 0; i < QUEEN; i++)             // 按行打印
    {
	for (j = 0; j < QUEEN; j++)
	{
	    if (a[i] != j)                   // a[i] 中存放的是皇后的列，i 表示为皇后的行
		printf("%c",'.');
	    else
		printf("%c",'#');
	}
	printf("\n");
    }
    for (i = 0; i < QUEEN; i++)
	printf("%d", a[i]);
    printf("\n");
    printf("--------------------------------\n");
}

void queen()           // 皇后程序
{
    int n = 0;
    int i = 0, j = 0;
    while (i < QUEEN)
    {
	while(j < QUEEN)   // 对 i 行的每一列进行探测，看是否可以放置皇后
	{
	    if (valid(i, j)) // 可以防止皇后
	    {
		a[i] = j;
		j = 0;       // 在i放置完皇后之后，需要探测下一行的皇后位置，下一行需要从第0列开始探测
		break;
	    }
	    else 
	    {
		++j;         // 第j列不可以放置皇后，则探测下一列
	    }
	}
	if (a[i] == INT_MIN) // 在i行无法放置皇后，说明前面放置有误，需要回溯
	{
	    	if (i == 0)  // i 已经为0 无法回溯，所有的解已经探测出，跳出程序。
		    break;
		else         // 否则回溯
		{
		    --i;        // 回到上一行
		    j = a[i] + 1; //　ｊ　变为原来位置的下一个地方
		    a[i] = INT_MIN;　// 　上一行的位置清除，重新探测
		    continue;    // 下一次循环
		}
	}
	if (i == QUEEN - 1)      //  在最有一行找到了皇后的位置，输出一个结果
	{
	    printf("answer %d: \n",++n);
	    print();
	    j = a[i] + 1;         // 清除最后一行的皇后的位置，找其他的解
	    a[i] = INT_MIN;
	    continue;            //　这个很重要
	}
	++i;
    }
}
int main()
{
    init();
    queen();
    return 0;
}
