/*
TASK: Alphacode
Input:
25114
1111111111
3333333333
10 
101 
110 
1101 
1022 
1010
0
Output:
6
89
1
1
1
1
2
1
*/
#include <iostream>
#include <vector>

using namespace std;

int count(string str)
{
    vector<int> cnt(str.length()+1);
    cnt[0]=1;
    cnt[1]=1;
    for(int i=1;i<str.length();i++)
    {
        if(((str[i]-'0'+(str[i-1]-'0')*10)>26)||(str[i-1]=='0'))
            cnt[i+1]=cnt[i];
        else if (str[i]=='0')
            cnt[i+1]=cnt[i-1];
        else    
            cnt[i+1]=cnt[i]+cnt[i-1];
    }
    return cnt[str.length()];
}

int main()
{
    string str;
    cin>>str;
    vector<string> inputs;
    while(str!="0")
    {
        inputs.push_back(str);
        cin>>str;
    }
    for(int i=0;i<inputs.size();i++)
    {
        cout<<count(inputs[i])<<endl;
    }
    return 0;
}
