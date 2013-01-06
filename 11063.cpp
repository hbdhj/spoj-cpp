/*
11063. AP - Complete The Series (Easy)
Input:
1
3 8 55
Output:
10
1 2 3 4 5 6 7 8 9 10
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i, j, tN;
    long long int tm, ltm, sum, num, d, a, b, c;
    cin>>tN;
    vector<int> input;
    for(i=0;i<tN;i++)
    {
        cin>>tm;
        cin>>ltm;
        cin>>sum;
        input.push_back(tm);
        input.push_back(ltm);
        input.push_back(sum);
    }
    for(i=0;i<tN;i++)
    {
        a=input[3*i+1]+input[3*i];
        b=input[3*i]*13+input[3*i+1]+2*input[3*i+2];
        c=12*2*input[3*i+2];
        cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
        //cout<<b*b-2*ac<<endl;
        /*num = b+sqrt(b*b-2*ac);
        cout<<num<<endl;
        d=(input[3*i+1]-input[3*i])/(num-5);
        for(j=0;j<num-1;j++)
        {
            cout<<input[3*i]+(j-2)*d<<" ";
        }
        cout<<input[3*i+1]+2*d<<endl;*/
    }
    return 0;
}