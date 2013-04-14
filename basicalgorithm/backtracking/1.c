#include <stdlib.h>
#include <stdio.h>

struct point
{
    long x;
    long y;
};

struct point data[50000];

long d(struct point &a,struct point &b)
{
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

double rx(struct point &a,struct point &b)
{
    return (double)(a.y + b.y)*(b.y - a.y) / (b.x - a.x) / 2.0 + (a.x + b.x) / 2.0;
}
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
	    scanf("%ld %ld", &data[i].x, &data[i].y);
	    i++;
	}
	int max;
	max = 0;
	struct point p1, p2;
	int k, l;
	for (k = 0; k < N; k++)
	    for (l = k + 1; l < N; l++)
	    {
		if (d(data[k], data[l]) > max)
		{
		    p1 = data[k];
		    p2 = data[l];
		}
	    }
	
	double x;
	x = rx(p1, p2);
	printf("Case #%f:", x);
    }
    return 0;
}
