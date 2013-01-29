/*
13367. EVEN COUNT
Sample Input:
2
2 12
4 23
Sample Output:
6
12
*/

#include <iostream>
#include <vector>
using namespace std;

int f(int n)
{
    int ret=1;
    int m=n;
    while(n)
    {
        ret*=n%10;
        if(ret%2==0)
            return 0;
        n=n/10;
    }
    return ret;
}

int even(int l, int r)
{
    int ret=0;
    for(int i=l;i<=r;i++)
        if(f(i)%2==0)
            ret++;
    return ret;        
}

int main()
{
    //4 69 844 9219 96094
    vector<unsigned long long> even_num(10, 0);
    even_num[0]=4;
    unsigned long long rem=5;
    unsigned long long base=10;
    for(int i=1;i<10;i++)
    {
        base*=10;
        rem*=5;
        even_num[i]=base-rem-(base/10-even_num[i-1]);
    }
    for(int i=0;i<10;i++)
    {
        printf("%lld ", even_num[i]);
    }
    printf("\n");
    /*
    int i,t;
    scanf("%d", &t);
    vector<int> ls(t,0);
    vector<int> rs(t,0);
    for(i=0;i<t;i++)
        scanf("%d %d", &ls[i], &rs[i]);
    for(i=0;i<t;i++)
        printf("%d\n", even(ls[i], rs[i]));*/
    return 0;
}