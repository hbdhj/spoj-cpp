/*
TASK: SHAPE GAME
t<=100
1<=n<=300
1<=i,j<=300
i!=j.
Sample Input:-
1
1
1 2
1 4
2 3
2 5
2 6
3 6
4 7
5 6
6 7
-1 -1
Sample Output:-
YES
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int i,j,t,s,e;
    scanf("%d", &t);
    vector<int> starts(t,0);
    vector<int> max(t,0);
    vector<vector<int> > points(t,vector<int>(300,0));
    for(i=0;i<t;i++)
    {
        scanf("%d", &starts[i]);
        scanf("%d %d", &s, &e);
        while((s!=-1)&&(t!=-1))
        {
            points[i][s-1]++;
            points[i][e-1]++;
            if(s>max[i])
                max[i]=s;
            if(e>max[i])
                max[i]=e;
            scanf("%d %d", &s, &e);
        }
    }
    //printf("%d\n", t);
    for(i=0;i<t;i++)
    {
        //printf("%d\n", starts[i]);
        //printf("%d\n", max[i]);
        bool ok=true;
        for(j=0;j<max[i];j++)
        {
            //printf("%d ", points[i][j]);
            if(points[i][j]%2!=0)
            {
                ok=false;
                break;
            }
        }
        //printf("\n");
        if(ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
