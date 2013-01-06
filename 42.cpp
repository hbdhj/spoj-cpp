/*
 * 2012/11/29
 */
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
using namespace std; 

#define TASK_NUM 10000

string reverse(string input)
{
    string ret = input;
    int size = input.size();
    for (int i=0;i<size;i++)
        ret[i] = input[size-1-i];
    int pos=0;
    while(ret[pos]=='0')
    {
        pos++;
    }
    if(pos)
        ret = ret.substr(pos, ret.size()-1);
    return ret;
}

string getArithmetics(string input)
{    
    string str1, str2;
    size_t pos = input.find(' ');
    str1 = input.substr(0, pos);
    str2 = input.substr(pos+1, input.size()-1);
    string str1_r = reverse(str1);
    string str2_r = reverse(str2);
    unsigned long i1, i2, r;
    sscanf(str1_r.c_str(), "%d", &i1);
    sscanf(str2_r.c_str(), "%d", &i2);
    //cout<<i1<<" "<<i2<<endl;
    r=i1+i2;
    stringstream ss;
    ss << r;
    string ret = ss.str();
    return reverse(ret);
}

int main() 
{
    //int taskNumber = 1;
    //cin>>taskNumber; // Read the next number
    char task_number[7];
    cin.getline (task_number,7); // Read the next number
    int taskNumber;
    sscanf (task_number,"%d", &taskNumber);  
    if ((taskNumber>0)&&(taskNumber<=TASK_NUM))
    {
        vector<string> input;
        for(int i= 0; i<taskNumber; i++) 
        {
            char in[100];
            cin.getline (in, 100); // Read the next number
            string str=in;
            input.push_back(str);
        }
        for(int i= 0; i<input.size(); i++)
        {    
            cout<<getArithmetics(input[i])<<endl;
        }
    }      
    return 0;
}
