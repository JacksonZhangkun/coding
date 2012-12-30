// Given an image represented by an N*N matrix, where each pixel in the image is
// 4 bytes, write a method to rotate the image by 90 degrees.
// Please think about the N*M matrix

#include<stdlib.h>
#include<stdio.h>

// Solution 1:
void rotatematrix(long** a,int N){           //c���������޷�����
	int layer;                               //����ά���鵱��������ʱ�򣬱���ָ������ά����С����ʡ�Ե�һά
	for(layer=0;layer<N/2;layer++){          //���ǲ���ʡ�Եڶ�ά���߸���ά�Ĵ�С�������籾���� ��ָ���ָ��
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
	rotatematrix((long**)a,5);     //������Ҫǿ��ת��

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
