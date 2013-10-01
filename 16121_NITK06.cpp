/*
 TASK: MODIFY SEQUENCE
 Input:

2
2
1 2
2
2 2

Output:

NO
YES

 */
#include <stdio.h>

int main()
{
    int t, n, i, m;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        bool ret=true;
        int left = 0;
        for (i=0; i<n; i++) 
        {
            scanf("%d", &m);
            if (i==0) 
                left=m;
            else
            {
                if (m<left) 
                    ret=false;
                else
                    left=(m-left);
            }
        }
        if (ret&&left==0) 
            printf("YES\n");
        else
            printf("NO\n");
    }
        return 0;
}