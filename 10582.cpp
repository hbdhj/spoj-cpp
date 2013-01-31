/*
10582. subarrays
Input:
9
1  2  3  1  4  5  2  3  6
3
Output:
3 3 4 5 5 5 6
*/
#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;
#define SI(n) scanf("%d",&n)

#define N 1000000
int vals[N+1];
typedef multiset<int,greater<int> > mi;

void solve(int n, int k)
{
  mi v(vals,vals+k);
  int i=k;
  for(;i<n;++i)
  {
    printf("%d ",*v.begin());
    v.erase(v.find(vals[i-k]));
    v.insert(vals[i]);
  }
  printf("%d\n",*v.begin());
}

int main()
{
  int t,i;
  int n,k;
  SI(n);
  for(i=0;i<n;++i) SI(vals[i]);
  SI(k);
  solve(n,k);
  return 0;
}