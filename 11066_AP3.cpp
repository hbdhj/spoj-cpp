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
    vector<long long int> input;
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
        b=input[3*i]*7+input[3*i+1]*5+input[3*i+2]*2;
        c=12*input[3*i+2];
        /*cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
        cout<<b*b-4*a*c<<endl;
        num1 = (b-sqrt(float(b*b-4*a*c)))/a/2;*/
        num = (b+sqrt(float(b*b-4*a*c)))/a/2;
        /*cout<<num1<<", "<<num2<<endl;*/       
        cout<<num<<endl;
        d=(input[3*i+1]-input[3*i])/(num-6);
        for(j=0;j<num-1;j++)
        {
            cout<<input[3*i]+(j-2)*d<<" ";
        }
        cout<<input[3*i+1]+3*d<<endl;
    }
    return 0;
}