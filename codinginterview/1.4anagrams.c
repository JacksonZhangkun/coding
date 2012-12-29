// Write a method to decide if two strings are anagrams or not
// An anagram is a word or phrase formed by changing the order of the letters in another word or phrase.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Solution 1: Firstly sort the string and then compare the two string

//Solution 2: Check if the two strings have identical counts for each unique char.
int anagram(char* s1,char* s2){
	if(strlen(s1)!=strlen(s2))return 0;
	int letters[256]={0};
	unsigned int i;
	for(i=0;i<strlen(s1);i++)
		letters[(int)(s1[i])]++;
	for(i=0;i<strlen(s2);i++){
		if(letters[(int)(s2[i])]==0)return 0;
		letters[(int)(s2[i])]--;
	}
	return 1;
}
int main(){
	char s1[]="hello";
	char s2[]="helll";
	if(anagram(s1,s2))
		printf("they are anagrams");
	else
		printf("they are not anagrams");
	return 0;
}







