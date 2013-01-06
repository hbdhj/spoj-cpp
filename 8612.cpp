/*Deng Haijun 2012/12/10 SPOJ 8612 */

#include <iostream>
#include <vector>

using namespace std;

int coutTHT(string str)
{
    int num[8];
    for(int i = 0; i<8; i++)
        num[i] = 0;
    int d = 'T' - 'H';
    for(int i = 0; i<str.size()-2; i++)
    {
        int N = (str[i]-'H')/d*4+(str[i+1]-'H')/d*2+(str[i+2]-'H')/d;
        num[N]++;
    }
    for(int i = 7; i>=0; i--)
        cout<<" "<<num[i];    
    cout<<endl;
    return 0;
}

int main(int argc, char **argv)
{
    int tN;
    cin>>tN;
    vector<int> intVector;
    vector<string> stringVector;
    for(int i=0; i<tN; i++)
    {
        int in;    
        cin>>in;
        string str;
        cin>>str;
        intVector.push_back(in);
        stringVector.push_back(str);
    }
    for(int i=0; i<tN; i++)
    {
        cout<<intVector[i];
        coutTHT(stringVector[i]);
    }
	return 0;
}
