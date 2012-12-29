//1.3 Design an algorithm and write code to remove the duplicate characters
//in a string without using any additional buffer.
//Note: One or two additional variables are fine
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

// Solution 1
void removeDuplicates1(char* str)
{
	if(str==NULL)return;         //不能忽视
	int len=strlen(str);
	if(len<2)return;

	int tail=1;
	int i,j;
	for(i=1;i<len;i++)
	{
		for(j=0;j<tail;j++)
		{
			if(str[i]==str[j])break;
		}
		if(j==tail){                //比完后发现现有的字符中没有和str[i]相同的 故将其收入怀中。
			str[tail]=str[i];
			++tail;
		}
	}
	str[tail]=0;                   //very important
}

//Solution 2  Hash
void removeDuplicates2(char* str)
{
	if(str==NULL)return;
	int len=strlen(str);
	if(len<2)return;

	bool* hit=new bool[256];
	unsigned int i;
	int tail=1;
	for(i=0;i<256;i++)
		hit[i]=false;
	hit[static_cast<int>(str[0])]=true;            //不转换会出现array subscript has type 'char' [-Wchar-subscripts] 错误
	for(i=1;i<strlen(str);i++){
		if(!hit[static_cast<int>(str[i])]){
			str[tail]=str[i];
			tail++;
			hit[static_cast<int>(str[i])]=true;
		}
	}
	str[tail]=0;

	}
int main() {
	char p[]="hello111234";
	removeDuplicates2(p);
	printf("%s",p);
	return 0;
}





