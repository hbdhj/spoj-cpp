#include <iostream>
#include <vector>
#include <map>
using namespace std; 

#define TESTCASE_NUM_MAX 100
#define OP_NUM_MAX 1000
#define HASH_KEY 101
//int printMapKey(vector<string> input)
int printMapKey(map<int, string> &input)
{
    cout<<"PrintMapKey"<<endl;
    map<int, string>::iterator it;
    for(it=input.begin(); it!=input.end(); it++)
    {
        //if(input[i].size())
        cout<<(*it).first<<":"<<(*it).second<<endl;;
    }
    return 0;
}

//int getHashKey(vector<string>mp, string str)
int getHashKey(string str)
{
    int h;
    for(int i=0;i<str.size();i++)
        h+=str[i]*(i+1);
    h *= 19;
    return h%HASH_KEY;
    //int j=0;
    //return (h+j*j+23*j)%HASH_KEY;
}
/*    
    while(mp[hash].size()&&(j<20))
    {
        j++;
        hash = (h+j*j+23*j)%HASH_KEY;
    }
    if(j!=20)
        return hash;
    else
        return -1;
}*/

//int createMap(vector<string> &mp, vector<string> input)
int createMap(map<int, string> &mp, vector<string> input)
{
    //vector<string> mp(101, "");
    for(int i=0; i<input.size(); i++)
    {
        size_t pos = input[i].find(':');
        string act = input[i].substr(0, pos);
        string value = input[i].substr(pos+1, input[i].size()-1); 
        cout<<"act = "<<act<<", value = "<<value<<endl;
        if(act=="ADD")
        {
            //int hashValue = getHashKey(mp, value);
            int hashValue = getHashKey(value);
            cout<<"hashValue("<<value<<") = "<<hashValue<<endl;
            //if(hashValue>=0)
            map<int,string>::iterator it = mp.find(hashValue);
            if(it != mp.end())
                mp[hashValue] = value;
        }
        if(act=="DEL")
        {
            int hashValue = getHashKey(value);
            cout<<hashValue<<endl;
            //if((hashValue>=0)&&(mp[hashValue]==value))
            //    mp[hashValue] = "";
            map<int,string>::iterator it = mp.find(hashValue);
            mp.erase(it);
        }
    }
    return 0;
}

int main()
{
    int tN = 1;
    cin>>tN;
    if (tN&&(tN<=TESTCASE_NUM_MAX))
    {
        vector<int> ip;
        vector< vector<string> > inputs;
        for(int i= 0; i<tN; i++) 
        {
            int opNum = 11;
            //cin>>opNum;
            if (opNum&&(opNum<=OP_NUM_MAX))
            {    
                vector<string> input;
                /*for(int i= 0; i<opNum; i++) 
                {
                    string str;
                    cin>>str;
                    input.push_back(str);
                }*/
                input.push_back("ADD:marsz");
                input.push_back("ADD:marsz");
                input.push_back("ADD:Dabrowski");
                input.push_back("ADD:z");
                input.push_back("ADD:ziemii");
                input.push_back("ADD:wloskiej");
                input.push_back("ADD:do");
                input.push_back("ADD:Polski");
                input.push_back("DEL:od");
                input.push_back("DEL:do");
                input.push_back("DEL:wloskiej");
                inputs.push_back(input);
            }
        }
        
        for(int i= 0;i<tN;i++)
        {
            //vector<string> mp(HASH_KEY, "");
            map<int, string> mp;
            createMap(mp, inputs[i]);
            printMapKey(mp);
        }
    }
    return 0;
}
