/*Deng Haijun 2012/12/11 400. To and Fro*/
#include <iostream>
#include <vector>
using namespace std;

int Feynman(int n)
{
    int ret = 0;
    for(int i=1;i<=n;i++)
        ret += i*i;
    return ret;
}
int main()
{
    int number;
    cin>>number;
    vector<int> numbers;
    while(number>0)
    {
        numbers.push_back(number);
        cin>>number;
    }
    for(int i=0;i<numbers.size();i++)
    {
        cout<<Feynman(numbers[i])<<endl;
    }
    return 0;
}
