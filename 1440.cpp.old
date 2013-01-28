/*
(m+n)/(m*n-1)=1/X
X(m+n)=m*n-1
(n-X)m=Xn+1
m=Xn+1/(n-X)
n^2-Xn=X^2+1
m=(X+sqrt(5*X^2+4))/2
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int getNM(int n)
{
float l = (n + sqrt(float(4+5*n*n)))/2;
float m=(l*n+1)/(l-n);
return m+l;
}
int main()
{
int tN;
cin>>tN;
vector<int> ns;
for(int i=0;i<tN;i++)
{
int n;
cin>>n;
ns.push_back(n);
}
for(int i=0;i<tN;i++)
{
cout<<getNM(ns[i])<<endl;
}
}