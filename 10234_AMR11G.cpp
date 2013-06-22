/*
Deng Haijun 2012/12/18
TASK: Here Be Dragons
Sample Input:
3
..
..D.
D..D
Sample Output:
Possible
You shall not pass!
You shall not pass!
10234. Here Be Dragons
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int tN;
    cin>>tN;
    vector<string> cods;
    for(int i=0;i<tN;i++)
    {
        string cod;
        cin>>cod;
        cods.push_back(cod);
    }
    for(int i=0;i<tN;i++)
    {
        bool pass = true;
        for(int j=0;j<cods[i].size();j++)
        {
            if(cods[i][j]=='D')
            {
                pass = false;
                break;
            }
        }
        if(pass)
            cout<<"Possible"<<endl;
        else
            cout<<"You shall not pass!"<<endl;
    }
    return 0;
}
