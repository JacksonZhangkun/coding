/*
 *  Coding Interview 1.2
 *	Function: Reverse a C-style string
 *  Created on: 2012-12-28
 *  Author: Shydaydreamer.Jackson
 */
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//Solution 1
char* strrev1(const char* str)
{
	int len=strlen(str);
	char* temp=malloc(sizeof(char)*(len+1));
	strcpy(temp,str);

	int i;
	for(i=0;i<len/2;i++)
	{
		char c=temp[i];
		temp[i]=temp[len-i-1];
		temp[len-i-1]=c;
	}
	return temp;
}

//Solution 2
char* strrev2(const char* str) {

	char* temp=malloc(sizeof(char)*(strlen(str)+1));
	strcpy(temp,str);
	char* ps=temp;
	char* pe=temp+strlen(str)-1;

	while(ps<pe)
	{
		char t=*ps;
		*ps++=*pe;
		*pe--=t;
	}
	return temp;
}

//Solution 3
//不用任何外部变量完成两个字符的交换 by exclusive or
char* strrev3(const char* str)
{
	char* temp=malloc(sizeof(char)*(strlen(str)+1));
	strcpy(temp,str);
	char* ps=temp;
	char* pe=temp+strlen(str)-1;

	while(ps<pe)
	{
		*ps^=*pe;
		*pe^=*ps;
		*ps^=*pe;
		ps++;pe--;
	}
	return temp;
	}
//Solution 4
//不用任何外部变量完成两个字符的交换  加法
char* strrev4(const char* str)
{
	char* temp=malloc(sizeof(char)*(strlen(str)+1));
	strcpy(temp,str);
	char* ps=temp;
	char* pe=temp+strlen(str)-1;

	while(ps<pe)
	{
		*ps=*ps+*pe;
		*pe=*ps-*pe;
		*ps=*ps-*pe;
		ps++;pe--;
	}
	return temp;
	}

//Solution 5
//改变原来的字符串了
char *strrev5(char *str)
{
    char temp;
    char *s1 = str;
    char *s2 = str+strlen(str)-1;

    for(;s1 < s2;s1++,s2--)
    {
        temp = *s1;
        *s1 = *s2;
        *s2 = temp;
    }
    return str;
}

int main() {
	char p[] = "hello";    //char* p="hello"  这样定义的指针p会被默认为 const char* 类型
	printf("%s\n",strrev1(p));
	printf("%s\n",strrev2(p));
	printf("%s\n",strrev3(p));
	printf("%s\n",strrev4(p));
	printf("%s\n",strrev5(p));
	return 0;
}

