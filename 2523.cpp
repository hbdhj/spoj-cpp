/*Deng Haijun 2012/12/14 
2523. Mispelling
Input:
4
4 MISSPELL
1 PROGRAMMING
7 CONTEST
3 BALLOON

Output:
1 MISPELL
2 ROGRAMMING
3 CONTES
4 BALOON
*/

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
    int tN;
    cin>>tN;
    vector<int> poss;
    vector<string> strs;
    for(int i=0; i<tN; i++)
    {
        int pos;
        cin>>pos;
        poss.push_back(pos);
        string str;
        cin>>str;
        strs.push_back(str);        
    }
    for(int i=0; i<tN; i++)
    {
        if(poss[i]<=strs[i].length())
        {
            cout<<i+1<<" "<<strs[i].substr(0, poss[i]-1)<<strs[i].substr(poss[i],strs[i].length())<<endl;
        }
    }
    return 0;
}
