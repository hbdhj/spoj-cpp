/*
TASK: HYDRO - Hydroelectric dams
ALGO:
Input:
2
3
2 0 2
6
3 0 0 2 0 4
Output:
2
10
*/
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
    int t, i, n, j;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        vector<int> h(n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&h[j]);
        }
        int water = 0;
        int p_l = 0;
        int p_r = n - 1;
        int max_l = h[p_l];
        int max_r = h[p_r];
        while(p_r>p_l)
        {
            if (max_l<max_r)
            {
                p_l++;
                if (h[p_l]>=max_l)
                {
                    max_l = h[p_l];
                }
                else
                {
                    water = water + (max_l - h[p_l]);
                }
            }
            else
            {
                p_r--;
                if (h[p_r]>=max_r)
                {
                    max_r = h[p_r];
                }
                else
                {
                    water = water + (max_r - h[p_r]);
                }
            }
        }
        printf("%d\n", water);
    }
    return 0;
}
