/*Deng Haijun 2012/12/11 74. Divisor Summation*/
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int DivisorSummation(int n)
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
    //cin>>tN;
    scanf("%d", &tN);
    //vector<int> numbers;
    int* numbers=new int[tN];
    //printf("%d\n",tN);
    //while(tN>0)
    for(int i=0;i<tN;i++)
    {
        int number;
        //cin>>number;
        scanf("%d", &number);
        //printf("%d\n",number);
        numbers[i]=number;
        //numbers.push_back(number);
        //tN--;
    }
    for(int i=0;i<tN;i++)
    {
        printf("%d\n",DivisorSummation(numbers[i]));
    }
    delete numbers;
    return 0;
}

