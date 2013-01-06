/*
 * 2012/11/29
 */
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include <complex>

using namespace std;

#define TASK_NUM 10000
#define COMPLEX complex<float> 

int strtoint(string str)
{
    int ret = 0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='m')
        {
            if((str[i-1]<='9')&&(str[i-1]>'0')&&(i))
                ret += (str[i-1]-'0')*1000;
            else
                ret += 1000;
        }
        if(str[i]=='c')
        {
            if((str[i-1]<='9')&&(str[i-1]>'0')&&(i))
                ret += (str[i-1]-'0')*100;
            else
                ret += 100;
        }
        if(str[i]=='x')
        {
            if((str[i-1]<='9')&&(str[i-1]>'0')&&(i))
                ret += (str[i-1]-'0')*10;
            else
                ret += 10;
        }
        if(str[i]=='i')
        {
            if((str[i-1]<='9')&&(str[i-1]>'0')&&(i))
                ret += str[i-1]-'0';
            else
                ret += 1;
        }
    }
    return ret;
}

string inttostr(int input)
{
    string ret;
    if(input/1000)
    {
        if((input/1000)>1)
            ret = char('0'+input/1000);
        ret += "m";
        input -= (input/1000)*1000;
    }
    if(input/100)
    {
        if((input/100)>1)
            ret += char('0'+input/100);
        ret += "c";
        input -= (input/100)*100;
    }
    if(input/10)
    {
        if((input/10)>1)
            ret += char('0'+input/10) ;
        ret += "x";
        input -= (input/10)*10;
    }
    if(input)
    {
        if(input>1)
            ret += char('0'+input);
        ret = ret + "i";
    }
    return ret;
}

int main() 
{
    char home_number[7];
    cin.getline (home_number,7); // Read the next number
    int homeNumber;
    sscanf (home_number,"%d", &homeNumber);    
    vector<string> outputs;
    for(int i=0; i<homeNumber; i++)
    {
        char in[30];
        char str1[15];
        char str2[15];
        cin.getline (in, 30); // Read the next home location
        sscanf (in,"%s %s", &str1, &str2);
        string ret = inttostr(strtoint(str1)+strtoint(str2));
        outputs.push_back(ret);
    }
    for(int i = 0; i<outputs.size(); i++)
    {
        cout<<outputs[i]<<endl;
    }
    return 0;
}
