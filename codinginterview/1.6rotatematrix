// Given an image represented by an N*N matrix, where each pixel in the image is
// 4 bytes, write a method to rotate the image by 90 degrees.
// Please think about the N*M matrix

#include<stdlib.h>
#include<stdio.h>

// Solution 1:
void rotatematrix(long** a,int N){           //c语言里面无法传递
	int layer;                               //将二维数组当作参数的时候，必须指明所有维数大小或者省略第一维
	for(layer=0;layer<N/2;layer++){          //但是不能省略第二维或者更高维的大小，或者如本程序 用指针的指针
		int offset;
		for(offset=0;offset<N-layer*2-1;offset++){
			int temp;
			temp=*((long*)a+layer*N+(layer+offset));
			*((long*)a+layer*N+(layer+offset))=*((long*)a+(layer+offset)*N+(N-layer-1));
			*((long*)a+(layer+offset)*N+(N-layer-1))=*((long*)a+(N-layer-1)*N+(N-layer-1-offset));
			*((long*)a+(N-layer-1)*N+(N-layer-1-offset))=*((long*)a+(N-layer-1-offset)*N+(layer));
			*((long*)a+(N-layer-1-offset)*N+(layer))=temp;
		}
	}
}
int main(){
	int i,j;
	long a[5][5];
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			a[i][j]=i+j;
	for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
				printf("%ld  ",a[i][j]);
			printf("\n");
		}
	printf("\n\n");
	rotatematrix((long**)a,5);     //这里需要强制转化

	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			printf("%ld  ",a[i][j]);
		printf("\n");
	}
	return 0;
}

/* Result1:
 * 0  1  2  3  4
 * 1  2  3  4  5
 * 2  3  4  5  6
 * 3  4  5  6  7
 * 4  5  6  7  8


 * 4  5  6  7  8
 * 3  4  5  6  7
 * 2  3  4  5  6
 * 1  2  3  4  5
 * 0  1  2  3  4
 *
 */
