#include <iostream>
using namespace std;
string getR(int input)
{
if(input == 1)return "2(0)";else if(input == 2)return "2";
int n = 0;
int i = input;
int j = 1;
while(i/2>0){n++;j*=2;i=i/2;}
string ret;
if(n==1)ret="2";else ret="2("+getR(n)+")";
if((input-j)>0)return ret+"+"+getR(input-j);else return ret;    
}
int main()
{
int is[7] = {137, 1315, 73, 136, 255, 1384, 16385};
for(int i=0; i<7; i++)cout<<is[i]<<"="<<getR(is[i])<<endl;
return 0;
}