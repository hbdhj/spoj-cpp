/*
6297. Decipher
(x1+x2+x3)=-a;
x1*x2+x1*x3+x2*x3=b;
ans=a*a-2*b;
6297. Decipher
Input:
1
-6 11 -6
Output:
14
*/
#include <vector>
#include <stdio.h>
using namespace std;
int main()
{
    int i,t;
    scanf("%d",&t);
    vector<long long int> inputs(t*3);
    for(i=0;i<t;i++)
        scanf("%lld %lld %lld", &inputs[i*3], &inputs[i*3+1], &inputs[i*3+2]);
    for(i=0;i<t;i++)
        printf("%lld\n", inputs[i*3]*inputs[i*3]-2*inputs[i*3+1]);
    return 0;
}