/*
TASK: Rachu
Input:
2 1
Output:
1
Input:
4 2
Output:
3
*/
#include <stdio.h>
int main()
{
    int n, r;
    scanf("%d %d", &n, &r);
    if(n<r)
        printf("-1\n");
    else if((n==r)||(r==1))
        printf("1\n");
    else 
    {
        int c=n-r;
        unsigned long long int ret=1;
        int p=1;
        while(p<=c)
        {
            ret=ret*(c-p+2)/p;
            //printf("ret = %lld, p = %d\n", ret, p);
            p++;
        }
        printf("%lld\n", ret%10000007);
    }
    return 0;
}
