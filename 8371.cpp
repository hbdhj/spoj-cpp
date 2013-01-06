/*Deng Haijun 2012/12/10 SPOJ 8371 */

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

float getS(int V)
{
    float a = pow(float(V)*4, float(1.0)/3);
    return sqrt(float(3.0))*(a*a/2 + 4*float(V)/a);
}

int main(int argc, char **argv)
{
    int tN;
    cin>>tN;
    vector<int> VQ;
    for(int i=0; i<tN; i++)
    {
        int V;    
        cin>>V;
        VQ.push_back(V);
    }
    for(int i=0; i<tN; i++)
    {
        printf("%.10f\n", getS(VQ[i]));
    }
	return 0;
}
