// Question1:
// Implement an algorithm to determine if a string has all unique characters.
// What if you can not use an additional data structures?

#include <iostream>
#include<string>
using namespace std;

//Solution 1.1 : Hash
//time complexity:O(N)
//space complexity:O(N)
bool isUniqueChar21(string str)
{
	bool boolean[256];
	unsigned int i=0;
	for(;i<str.length();i++)
	{
		int var=str[i];
		if(boolean[var])return false;
		boolean[var]=true;
	}
	return true;
}

//Solution 1.2: Bit vector
//time complexity:
//space complexity:
bool isUniqueChar22(string str)
{
	int checker=0;
	unsigned int i=0;
	for(;i<str.length();i++)
	{
		int var=str[i]-'a';
		if(checker&(1<<var))return false;
		checker |=(1<<var);
	}
	return true;
}

//Solution 1.3:  Sort the string in O(NlogN) and check the neighboring characters

//Solution 1.4:  two for loop like the bubble sort
//time complexity: O(N)
bool isUniqueChar24(string str)
{
	unsigned i,j;
	for(i=0;i<str.length()-1;i++)
		for(j=i+1;j<str.length();j++)
		{
			if(str[i]==str[j])return false;
		}
	return true;
}


int main() {
	string str("hello world");
	if(isUniqueChar24(str))
		cout<<"unique string"<<endl;
	else
		cout<<"not unique string"<<endl;
	return 0;
}
