/*
 * 2012/11/28
 */
#include <iostream>
#include <math.h>
#include <vector>

#define MAX_CASE_NUM 10000

using namespace std; 

vector<int> strSplit(string str, char c)
{
    vector<int> ret;
    while(str.size())
    {
        size_t pos = str.find(c);
        if(pos!=string::npos)
        {
            if(pos)
            {
                string intStr = str.substr(0, 1);
                int i;
                scanf(intStr.c_str(),"%d", &i);
                ret.push_back(i);
                cout<<i<<" ";
                str = str.substr(pos+1, str.size());
            }
            else
            {
                str = str.substr(1, str.size());
            }
        }
    }
    cout<<endl;
    return ret;
}
int completeSequence(string str1, string str2)
{
    cout<<"str1 = "<<str1<<endl;
    cout<<"str2 = "<<str2<<endl;
    return 0;
}

int main() 
{
  int caseNum;
  //cin>>caseNum; // Read the next number
  caseNum=3;
  if ((caseNum>0)&&(caseNum<MAX_CASE_NUM))
  {
    vector<string> inputs;
    /*for(int i =0; i<caseNum; i++) 
    {
        string caseStr1, caseStr2;
        cin>>caseStr1; // Current number and expected number
        inputs.push_back(caseStr1);
        cin>>caseStr2; // Read the sequence
        inputs.push_back(caseStr2);
    }*/
    strSplit("6 3", ' ');
    strSplit("1 2 3 4 5 6", ' ');
    strSplit("1  2  3  4  5  6", ' ');
    inputs.push_back("6 3");
    inputs.push_back("1 2 3 4 5 6");
    inputs.push_back("8 2");
    inputs.push_back("1 2 4 7 11 16 22 29");
    inputs.push_back("1 10");
    inputs.push_back("3");
    for(int i =0; i<caseNum; i++) 
    {
        completeSequence(inputs[i*2], inputs[i*2+1]);
    }
  }
  return 0;
}
