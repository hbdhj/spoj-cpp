/* Deng Haijun 2012/12/17
4300. Rectangles
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int Rectangles(int n)
{
    int ret = 0;
    int sq = int(sqrt(float(n)));
    for(int i=2;i<=sq;i++)
        if((n%i)==0)
            ret++;
    return ret+1;
}

int main()
{
    int tN;
    scanf("%d", &tN);
    int ret=0;
    for(int i=0;i<tN;i++)
    {
        //cout<<"Rectangles("<<i+1<<") = "<<Rectangles(i+1)<<endl;
        ret+=Rectangles(i+1);
    }
    printf("%d\n", ret);
    return 0;
}