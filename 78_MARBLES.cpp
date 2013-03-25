/*
78. Marbles
Input:
2
10 10
30 7

Output:
1
475020
*/
#include <stdio.h>
#include <stdlib.h>

unsigned long long comb(int a, int b)
{
  int min = b > a-b ? a-b : b;
  unsigned long long ans = 1;
  int i;
  for(i=1;i<=min;i++)
      {
         ans = (ans*(a - i + 1))/i ;    
      }        
  return ans;    
}

int main()
{
 int t;
 scanf("%d",&t);
 for(int i=0;i<t;i++)
         {
            int a,b;
            scanf("%d %d",&a,&b);
            if (a==b)
                printf("1\n");
            else
                printf("%llu\n",comb(a-1,b-1));            
         }
  system("PAUSE");
  return 0;       
}