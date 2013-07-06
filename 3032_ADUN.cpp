/*
 TASK: Adding two numbers
 */
#include <iostream>
using namespace std; 
string rev(string s)
{
string r = s;
int sz = s.size();
for (int i=0;i<sz;i++)
r[i] = s[sz-1-i];
return r;
}
string Add(string s1, string s2)
{
string b, s, ret;
if (s1.size()>s2.size())
{
b = "0" + s1;
s = s2;
}
else
{
b = "0" + s2;
s = s1;
}
b = rev(b);
s = rev(s);
ret = b;
int ss = s.size();
int bs = b.size();
int in = 0;
for(int i=0; i<ss; i++ )
{
if(((b[i]+s[i]+in)-'0')>'9')
{
ret[i] = b[i]+s[i]+in-'0' -10;
in = 1;
}
else
{
ret[i] = b[i]+s[i]+in-'0';
in = 0;
}
}
for(int i=ss; i<bs; i++ )
{
if((b[i]+in)>'9')
{
ret[i] = b[i]+in-10;
in = 1;
}
else
{
ret[i] = b[i]+in;
in = 0;
}
}
ret = rev(ret);
while ((ret[0]=='0')&&(ret.size()>1))
ret=ret.substr(1, ret.size()-1);
return ret;
}

int main() 
{
string s1,s2;
cin>>s1;
cin>>s2;
cout<<Add(s1,s2)<<endl;
return 0;
}
