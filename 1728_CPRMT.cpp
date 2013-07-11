/*
TASK: Common Permutation
Sample input:
pretty
women
walking
down
the
street
Sample output:
e
nw
et 
*/
#include <stdio.h>

int CommonPermutation(string str1, string str2)
{
	vector<int> alpha1(26,0);
	for(int i=0;i<str1.length();i++)
	{
		int index = str1[i]-'a';
		if((index>=0)&&(index<26))
			alpha1[index]++;
	}
	vector<int> alpha2(26,0);
	for(int i=0;i<str2.length();i++)
	{
		int index = str2[i]-'a';
		if((index>=0)&&(index<26))
			alpha2[index]++;
	}
	int ret=0;
	for(int i=0;i<26;i++)
	{
		if((alpha1[i]>0)&&(alpha2[i]>0))
			ret++;
	}
	return ret;
}
int main()
{
	CommonPermutation("pretty","women");
	CommonPermutation("walking","down");
	CommonPermutation("street","the");
	return 0;
}
