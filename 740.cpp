/*
740. Treats for the Cows
DP
Input:
5
1
3
1
5
2
Output:
43
*/
#include <cstdio>
#include <vector>
#define max(a,b) a>b?a:b
using namespace std;
int age = 1;
vector<int> trts;
vector<vector<int> > DP;
int treats(int l,int r, int age)
{
  if(l==r)
  {
    DP[l][r] = trts[l]*age;
    return trts[l]*age;
  }
  if(DP[l][r]!=0)
    return DP[l][r];
  DP[l+1][r] = treats(l+1,r,age+1);
  DP[l][r-1] = treats(l,r-1,age+1);
  int val = max(DP[l+1][r]+trts[l]*age,DP[l][r-1]+trts[r]*age);
  return val;
}
int main()
{
  
  int N,a;
  scanf("%d",&N);
  DP.resize(N);
  for(int i=0;i<N;i++)
      DP[i].resize(N);
  trts.resize(N);
  for(int i=0;i<N;i++)
  {
    scanf("%d",&a);
    trts[i] = a;
  }
  printf("%d\n",treats(0,N-1,1));
  return 0;
}
