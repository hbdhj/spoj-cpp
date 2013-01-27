#include <iostream>
using namespace std;
int main()
{
string s;
cin>>s;
int a=0;
int r=0;
int c=0;
for (int i=0; i<s.length(); i++) {
if((s[i]>='A')&&(s[i]<='Z'))
{
if((((a+1)%4)>0)&&(c>0))
r+=4-(a+1)%4;
a=0;
c++;
}
else
a++;
}
cout<<r<<endl;
return 0;
}
