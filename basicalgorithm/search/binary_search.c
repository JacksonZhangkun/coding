#include<stdlib.h>
#include<stdio.h>
int Binary_Search(int *a,int n,int key){
    int low,high,mid;
    low = 0;
    high = n - 1;
    while (low <= high){
	mid = (low + high) / 2;
	if (key < a[mid])
	    high = mid - 1;
	else if (key > a[mid])
	    low = mid + 1;
	else 
	    return mid;
    }
    return -1;
}
int main(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("%d\n",Binary_Search(a,10,11));
    return 0;

}
