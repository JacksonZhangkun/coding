//source here
//source here
#include <stdlib.h>
#include <stdio.h>

long data[50000][2];

int main()
{
    long T;
    long N;
    scanf("%d", &T);
    int c = 1;
    while (T--)
    {
    scanf("%d", &N);
    long i = 0;
	while (N--){
	    scanf("%ld %ld", &data[i][0], &data[i][1]);
	    i++;
	}
    N = i;
	long max = 0;
    long x1 , y1 , x2 ,y2;
    int k, l;
	for (k = 0; k < N; k++)
	    for (l = k + 1; l < N; l++)
	    {
            long tmp = (data[k][0] - data[l][0]) * (data[k][0] - data[l][0]) + (data[k][1] - data[l][1]) * (data[k][1] - data[l][1]);
		    if (tmp > max)
		    {
                x1 = data[k][0]; y1 = data[k][1];
                x2 = data[l][0]; y2 = data[l][1];
                max = tmp;
		    }
	    }
    double x;
    x = (y1+y2)*(y2-y1)*0.5/(x2-x1) + (x1+x2)*0.5;
	printf("Case #%d: %f", c++, x);
    }
    return 0;
}
