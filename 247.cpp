/*
247. Chocolate
algo: grace
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long LL;
int x[1010],y[1010];

bool myfun(int i,int j) 
{
    return (i>j);
}

int main()
{
    int t;
    int m,n,a,b;
    int xp,yp,xmul,ymul,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&m,&n);
        for(int i=0;i<m-1;i++)
        {
            scanf("%d",&a);
            x[i] = a;
        }
        for(int i=0;i<n-1;i++)
        {
            scanf("%d",&b);
            y[i] = b;
        }


        sort(x,x+m-1,myfun);
        sort(y,y+n-1,myfun);
        xp = 0, yp = 0;
        xmul = 1, ymul = 1;
        sum = 0;
        while(xp<m-1||yp<n-1)
        {
            if(yp == n-1 || (xp<m-1 && x[xp]>y[yp]))
            {
                ymul++;
                sum += xmul*x[xp];
                xp++;
            }
            else 
            {
                xmul++;
                sum += ymul*y[yp];
                yp++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
