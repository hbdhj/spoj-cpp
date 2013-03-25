/*Deng Haijun 2012/12/14 1163. Java vs C ++

Input:
long_and_mnemonic_identifier
anotherExample
i
bad_Style

Output:
longAndMnemonicIdentifier
another_example
i
Error!
*/

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    unsigned long long int n;
    cin>>n;
    while (n > 1)
    {
        if (n%2==0)
            n=n/2;
        else
            break;
        //    n=3*n+3;
    }
    if(n>1)
        cout<<"NIE"<<endl;
    else    
        cout<<"TAK"<<endl;
    return 0;
}
