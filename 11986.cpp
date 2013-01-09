#include <iostream>
using namespace std;
string itom(int n)
{
	string ret="";
	while(n>=1000)
	{
		ret+="M";
		n-=1000;
	}
	if(n>=500)
	{
		ret+="D";
		n-=500;
	}
	while(n>=100)
	{
		ret+="C";
		n-=100;
	}
	if(n>=50)
	{
		ret+="L";
		n-=50;
	}
	while(n>=10)
	{
		ret+="X";
		n-=10;
	}
	if(n>=5)
	{
		ret+="V";
		n-=5;
	}
	while(n)
	{
		ret+="I";
		n--;
	}
	return ret;
}

int mtoi(string str)
{
	int ret=0;
	for(int i=0;i<str.length();i++)
	{
		switch(str[i])
		{
			case 'I':
				ret+=1;
				break;
			case 'V':
				ret+=5;
				break;
			case 'X':
				ret+=10;
				break;
			case 'L':
				ret+=50;
				break;
			case 'C':
				ret+=100;
				break;
			case 'D':
				ret+=500;
				break;
			case 'M':
				ret+=1000;
				break;
		}
	}
	return ret;
}

int main()
{
	int i,l,r,out[5];
	for(i=0;i<1;i++)
	{
		char left[20], right[20], ac;
		scanf("%s %s %c", left, right, &ac);
		l=mtoi(left);
		r=mtoi(right);
		switch(ac)
		{
			case '+':
				out[i]=r+l;
				break;
			case '-':
				out[i]=l-r;
				break;
			case '*':
				out[i]=l*r;
				break;
			case '/':
				out[i]=l/r;
				break;
			case '%':
				out[i]=l%r;
				break;
		}
	}
	for(i=0;i<1;i++)
		printf("%s\n", itom(out[i]).c_str());
	return 0;
}
