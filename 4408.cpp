/*Deng Haijun 2012/12/13 4408. Build a Fence */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(int argc, char **argv)
{
    int L;
    cin>>L;
    vector<int> Ls;
    while(L>0)
    {
        Ls.push_back(L);
        cin>>L;
    }
    for(int i=0; i<Ls.size(); i++)
    {
        float ret=float(Ls[i])*float(Ls[i])/M_PI/2;
        printf("%.2f\n",ret);
    }
	return 0;
}
