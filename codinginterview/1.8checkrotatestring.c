// Question 1.8:
// Assume you have a method isSubString which checks if one word is a substring of another.
// Given two strings,s1 and s2,write code to check if s2 is a rotation of s1 using only one call
// to isSubString(i.e, "waterbottle" is a rotation of "erbottlewat")

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void strcat1(char *s1,const char *s2){  //标准库的strcat函数 对于s1和s2是同一个字符串时是不对的。
										//故重写一个
	while(*s1)s1++;
	int length=strlen(s2);
	while(length--){
		*s1++=*s2++;
	}
	*s1='\0';
}
int isSubstring(char *a,char *b){
	if(strlen(a)>strlen(b))return 0;
	int i,j;
	int alength=strlen(a);int blength=strlen(b);
	for(i=0;i<blength;i++){
		if(b[i]==a[0]){
			for(j=1;j<alength;j++)
				if(b[i+j]!=a[j])break;
			if(j==alength)return 1;
		}
	}
	return 0;
}
int isRotation(char *s1,char *s2){
	if(strlen(s1)==strlen(s2)){
		strcat1(s1,s1);
		return isSubstring(s2,s1);
	}
	return 0;
}
int main(){
	char s1[]="hello";
	char s2[]="ohelo";
	if(isRotation(s1,s2))
		printf("is rotation\n");
	else
		printf("is not rotation\n");
	return 0;
}

