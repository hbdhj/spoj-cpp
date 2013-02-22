/*
705. New Distinct Substrings
Input:
2
CCCCC
ABABA
Output:
5
9
*/
#include <vector>
#include <iostream>
#include <map>

using namespace std;
int get(string str)
{
    int len=str.length();
    vector<map<string, int> > vec(len-1);
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<len-i+1;j++)
        {
            string tocheck=str.substr(j,i);
            //cout<<"tocheck="<<tocheck<<endl;
            if(vec[i-1].find(tocheck)==vec[i-1].end())
                vec[i-1].insert(pair<string,int>(tocheck,1));
        }
    }
    int ret=1;
    for(int i=0;i<len-1;i++)
    {
        ret+=vec[i].size();
    }
    return ret;
}
int main()
{
    int n,i;
    cin>>n;
    vector<string> inputs(n);
    for(i=0;i<n;i++)
        cin>>inputs[i];
    for(i=0;i<n;i++)
        cout<<get(inputs[i])<<endl;
    return 0;    
}