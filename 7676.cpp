/*
Input:
1 10
100 777
-1 -1
Output:
46
8655
*/
#include <iostream>
#include <vector>

using namespace std;

unsigned long long int count(unsigned long long int i)
{
    cout<<"Count for "<<i<<endl;
    int ret=0;
    int base=1;
    while(i>0)
    {
        cout<<"i%10 = "<<i%10<<endl;
        ret+=(i%10+1)*(i%10)/2*base;
        cout<<"ret = "<<ret<<endl;
        base*=46;
        i=i/10;
    }
    return ret;
}
int main()
{
    cout<<count(9)<<endl;
    cout<<count(10)<<endl;
    cout<<count(19)<<endl;
    cout<<count(20)<<endl;
    cout<<count(90)<<endl;
    cout<<count(99)<<endl;
    cout<<count(100)<<endl;
    /*for(int i=1;i<100;i++)
    {
        cout<<count(i)<<", ";
        if(i%10==0)
            cout<<endl;
    }*/
}