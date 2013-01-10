/*
2742. Summing Sums
Input:
3 4
1
0
4

Output:
26
25
29
The following is a table of the cows' numbers for each turn:

          Cows' numbers
Turn    Cow1  Cow2  Cow3
 0        1     0     4
 1        4     5     1
 2        6     5     9
 3       14    15    11
 4       26    25    29
*/

#define MOD 98765431

#include <stdio.h>

int main()
{
    unsigned long long int ci, sum;
    int i,n,t;
    scanf("%d %d", &n, &t);
    vector<unsigned long long int> cows;
    for(i=0;i<n;i++)
    {
        scanf("%llu", &cows[i]);
    }
    printf("Turn    Cow1  Cow2  Cow3\n");
    for(i=0;i<t+1;i++)
    {
        printf(" %d       ",i);
        for(j=0;j<n;j++)
        {
            if()
        }
    }
    return 0;
}