/*
TASK: Multinomial numbers
*/
#include <iostream>

using namespace std;

int lastDigitFact(int n)
{
    int ret = 1;
    for(int i =2; i <=n; i++)
    {
        int t = i;
        while((t%10)==0)
        {
            t = t/10;
        }
        ret = ret*t;
        if(ret>99)
        {
            while((ret%10)==0)
            {
                ret = ret/10;
            }
            ret = ret%100;
        }
    }
    
    return ret%10;
}
int main()
{
    for(int i = 0; i<300; i++)
        cout<<lastDigitFact(i);
        //cout<<"lastDigitFact("<<i<<") = "<<lastDigitFact(i)<<endl;
    return 0;
}
