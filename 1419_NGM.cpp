/*Deng Haijun 2012/12/13 
TASK: A Game with Numbers
 */

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    unsigned long L;
    cin>>L;
    if(L%10==0)
        cout<<2<<endl;
    else    
        cout<<1<<endl<<L%10<<endl;
    return 0;
}
