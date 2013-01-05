#include <iostream>
using namespace std;
int main()
{
int tN,n,i,r=0;
cin>>tN;
for(i=0; i<tN; i++)
{
cin>>n;
if(n>0)
r+=n;
}
cout<<r<<endl;
return 0;
}
