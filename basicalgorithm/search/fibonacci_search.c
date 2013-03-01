#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 10	
void fibonacci(int *f){
    f[0] = 0;
    f[1] = 1;
    int i;
    for (i = 2;i < MAXSIZE;i++)
	f[i] = f[i - 1] + f[i - 2];
}
int fibonacci_search(int *a,int key,int n){
    int low = 0,high = n - 1;
    int mid = 0;
    int k = 0;
    int F[MAXSIZE];
    int i;
    fibonacci(F);
    while(n > F[k] - 1)
	k++;
    for (i = n;i < F[k] - 1;i++)
	a[i] = a[high];
    while (low <=  high){
	mid = low + F[k - 1]-1;
	if (a[mid] > key){
	    high = mid + 1;
	    k = k - 1;
	}
	else if (a[mid] < key){
	    low = mid + 1;
	    k = k - 2;
	}
	else {
	    if (mid < n)
		return mid;
	    else
		return n;
	}
    }
    return -1;
}
int main(){
    int a[MAXSIZE] = {1,16,24,35,47,59,62,73,88,99};
    int key;
    printf("please input the key you want to search:\n");
    scanf("%d",&key);
    int pos = fibonacci_search(a,key,MAXSIZE);
    if (pos != -1)
	printf("%d appear in the %d",key,pos);
    else
	printf("there is no %d appear in the array \n",key);

    return 0;
}
