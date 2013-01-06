/*
 * 2012/12/09 big number
 */
#include <iostream>
//#include <math.h>
#include <vector>

using namespace std; 

#define TASK_NUM 1

string reverse(string input)
{
    string ret = input;
    int size = input.size();
    for (int i=0;i<size;i++)
        ret[i] = input[size-1-i];
    return ret;
}


string getAddArithmeticsStr(string first_number, string second_number)
{
    string big, small, ret;
    if (first_number.size()>second_number.size())
    {
        big = "0" + first_number;
        small = second_number;
    }
    else
    {
        big = "0" + second_number;
        small = first_number;
    }
    big = reverse(big);
    small = reverse(small);        
    ret = big;
    int small_size = small.size();
    int big_size = big.size();
    int increase = 0;
    for(int i=0; i<small_size; i++ )
    {
        if(((big[i]+small[i]+increase)-'0')>'9')
        {
            ret[i] = big[i]+small[i]+increase-'0' -10;
            increase = 1;
        }
        else
        {
            ret[i] = big[i]+small[i]+increase-'0';
            increase = 0;
        }
    }
    for(int i=small_size; i<big_size; i++ )
    {
        if((big[i]+increase)>'9')
        {
            ret[i] = big[i]+increase-10;
            increase = 1;
        }
        else
        {
            ret[i] = big[i]+increase;
            increase = 0;
        }
    }
    ret = reverse(ret);
    while ((ret[0]=='0')&&(ret.size()>1))
        ret=ret.substr(1, ret.size()-1);
    
    return ret;
}


string getMinusArithmetics(string first_number, string second_number)
{
    string first_rev, second_rev, ret;
    first_rev = reverse(first_number);
    second_rev = reverse(second_number);        
    int second_size = second_number.size();
    int first_size = first_rev.size();
    int decrease = 0;
    ret = first_number;
    for(int i=0; i<second_size; i++ )
    {
        if(((first_rev[i]-second_rev[i]-decrease))<0)
        {
            ret[i] = first_rev[i]-second_rev[i]-decrease+'0'+10;
            decrease = 1;
        }
        else
        {
            ret[i] = first_rev[i]-second_rev[i]-decrease+'0';
            decrease = 0;
        }
    }
    for(int i=second_size; i<first_size; i++ )
    {
        if((first_rev[i]-decrease)<'0')
        {
            ret[i] = first_rev[i]-decrease+10;
            
            decrease = 1;
        }
        else
        {
            ret[i] = first_rev[i]-decrease;
            decrease = 0;
        }
    }
    ret = reverse(ret);
    while (ret[0]=='0')
        ret=ret.substr(1, ret.size()-1);
    return ret;
}


string getTimesArithmetics(char first_number, char second_number)
{
    int first = first_number - '0';
    int second = second_number - '0';
    if (first*second>9)
    {
        char cret_10 = first*second/10+'0';
        char cret_1 = first*second%10+'0';
        string ret(2, '0');
        ret[0] = cret_10;
        ret[1] = cret_1;
        return ret;
    }
    else
    {
        char cret = first*second+'0';
        string ret(1, '0');
        ret[0] = cret;
        return ret;
    }
}

string getTimesArithmetics(string first_number, char second_number)
{
    if(second_number=='0')
    {
        return "0";
    }
    if(second_number=='1')
    {
        return first_number;
    }
    string ret="0";
    string first_rev = reverse(first_number);
    //cout<<"first_rev = "<<first_number<<endl;
    int first_size = first_number.size();
    for(int i=0; i<first_size; i++)
    {
        string bit_ret = getTimesArithmetics(first_rev[i], second_number);
        //cout<<"bit_ret = "<<bit_ret<<endl;
        int bit = i;
        while (bit)
        {
            bit_ret = bit_ret + "0";
            bit--;
        }
        //cout<<"bit_ret = "<<bit_ret<<endl;
        ret = getAddArithmeticsStr(ret, bit_ret);
    }
    //cout<<ret<<endl;
    return ret;
}

int getArithmetics(string str1, string str2)
{
    //cout<<"str1 = "<<str1<<", str2 = "<<str2<<endl;
    if((str1.size()<10)&&(str2.size()<10))
    {
        unsigned long l1, l2;
        sscanf(str1.c_str(), "%ul", &l1);
        sscanf(str2.c_str(), "%ul", &l2);
        //cout<<"l1 = "<<l1<<", l2 = "<<l2<<endl;
        unsigned long r1, r2;
        r1 = (l1+l2)/2;
        r2 = (l1-l2)/2;
        //cout<<"r1 = "<<r1<<", r2 = "<<r2<<endl;
        cout<<(l1+l2)/2<<endl;
        cout<<(l1-l2)/2<<endl;
    }
    else
    {
        string ret1 = getAddArithmeticsStr(str1, str2);
        string ret2 = getMinusArithmetics(str1, str2);
        //cout<<"ret1 = "<<ret1<<", ret2 = "<<ret2<<endl;
        string ret1_1 = getTimesArithmetics(ret1, '5');
        string ret2_1 = getTimesArithmetics(ret2, '5');
        //cout<<"ret1_1 = "<<ret1_1<<", ret2_1 = "<<ret2_1<<endl;
        string ret1_2 = ret1_1.substr(0, ret1_1.size()-1);
        string ret2_2 = ret2_1.substr(0, ret2_1.size()-1);
        cout<<ret1_2<<endl;
        cout<<ret2_2<<endl;
    }
    return 0;
}

int main() 
{
    vector<string> input;
        
    for(int i = 0; i<2*TASK_NUM; i++)
    {
        string str;
        cin>>str; // Read the next number
        input.push_back(str);        
    }  
    for(int i= 0; i<TASK_NUM; i++) 
    {    
        getArithmetics(input[2*i], input[2*i+1]);
    }
    return 0;
}
