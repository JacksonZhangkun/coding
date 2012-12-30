// write a method to replace all spaces in a string with '%20'

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// Solution 1
void replacechar1(char* str){
	int i=0,spacecount=0;
	unsigned int length;
	while(i<strlen(str)){
		if(str[i]==' ')spacecount++;
		i++;
	}
	length=spacecount*2+strlen(str);
	str[length--]='\0';                      //remember this
	for(i=strlen(str)-1;i>=0;i--){           //这里的i一定要设定为有符号的 否则当i=0时 i--后将是一个正的数，循环一直跳不出；
		if(str[i]==' '){
			str[length--]='0';
			str[length--]='2';
			str[length--]='%';
		}
		else{
			str[length--]=str[i];
		}
	}
}
// Solution 2
void replacechar2(char* str){
	unsigned int i,tail;
	for(i=0,tail=0;i<strlen(str);){
		while(str[i]!=' '&& i<strlen(str))str[tail++]=str[i++];
		while(str[i]==' '&& i<strlen(str))i++;
		if(i<strlen(str))str[tail++]=' ';
	}
	str[tail]='\0';
	replacechar1(str);
}

int main(){
	char p[]="h      w";
	replacechar2(p);
	printf("%s",p);
	return 0;
}

// Result1:          h%20%20%20%20%20%20w
// Result2:          h%20w
