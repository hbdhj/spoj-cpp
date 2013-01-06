/*
394. Alphacode
Input:
25114
1111111111
3333333333
0
Output:
6
89
1
*/
#include <iostream>
#include <vector>

using namespace std;

int count(string str)
{
    if(str.length()>2)
    {
        int bp=0;
        for(int i=0; i<str.length()-1;i++)
            if(((str[i]-'0')*10+(str[i+1]-'0'))>26)
            {
                bp=i+1;
                break;
            }
        if(bp!=0)
        {
            cout<<"bp = "<<bp<<endl;        
            string head = str.substr(0, bp);
            string tail = str.substr(bp, str.length());
            cout<<"head = "<<head<<", tail = "<<tail<<endl;
            /*int d;
            sscanf(head.c_str(), "%d", &d);
            if((d>26)||(d<11))
                return count(tail);
            else
                return 2*count(tail);
            }*/
            return count(head)*count(tail);
        }
        else
        {
            /*string head = str.substr(0, str.length()/2-1);
            string tail = str.substr(str.length()/2+1, str.length());
            cout<<"head = "<<head<<", tail = "<<tail<<endl;*/
            return (str.length()+1)*str.length()-1;
        }    
    }
    else
    {
        int d;
        sscanf(str.c_str(), "%d", &d);
        if((d>26)||(d<11))
            return 1;
        else
            return 2;
    }
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
