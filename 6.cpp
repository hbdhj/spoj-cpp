/*
 * 2012/11/29
 */
#include  <iostream>
#include <math.h>
#include <vector>

using namespace std; 

#define TASK_NUM 1000

string reverse(string input)
{
    string ret = input;
    int size = input.size();
    for (int i=0;i<size;i++)
        ret[i] = input[size-1-i];
    return ret;
}

int printSpace(int i)
{
    while(i)
    {
        cout<<" ";
        i--;
    }
}
int printBash(int i)
{
    while(i)
    {
        cout<<"-";
        i--;
    }
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

int getAddArithmetics(string first_number, string second_number)
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
    if (ret[0]=='0')
        ret=ret.substr(1, ret.size()-1);
    int max_length = first_number.size();
    if ((second_number.size()+1)>max_length)
        max_length = second_number.size()+1;
    if (ret.size()>max_length)
        max_length = ret.size();
    printSpace(max_length - first_number.size());
    cout<<first_number<<endl;
    printSpace(max_length - second_number.size() -1);
    cout<<"+"<<second_number<<endl;
    printBash(max_length);
    cout<<endl;
    printSpace(max_length - ret.size());
    cout<<ret<<endl;
    return 0;
}

int getMinusArithmetics(string first_number, string second_number)
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
    int max_length = first_number.size();
    if ((second_number.size()+1)>max_length)
        max_length = second_number.size()+1;
    if (ret.size()>max_length)
        max_length = ret.size();
    printSpace(max_length - first_number.size());
    cout<<first_number<<endl;
    printSpace(max_length - second_number.size() -1);
    cout<<"-"<<second_number<<endl;
    printBash(max_length);
    cout<<endl;
    printSpace(max_length - ret.size());
    cout<<ret<<endl;
    return 0;
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

string getTimesArithmeticsStr(string first_number, string second_number)
{
    vector<string> retVector;
    string bit_ret, first_rev, second_rev;
    first_rev = reverse(first_number);
    second_rev = reverse(second_number);        
    int second_size = second_number.size();
    for(int i=0; i<second_size; i++ )
    {
        bit_ret = getTimesArithmetics(first_number, second_rev[i]);
        retVector.push_back(bit_ret);
    }
    string final_ret="0";
    for(int i=0; i<second_size; i++)
    {
        string bit_shift_ret = retVector[i];
        int bit = i;
        while (bit)
        {
            bit_shift_ret = bit_shift_ret + "0";
            bit--;
        }
        final_ret = getAddArithmeticsStr(final_ret, bit_shift_ret);
    }
    return final_ret;
}
int getTimesArithmetics(string first_number, string second_number)
{
    vector<string> retVector;
    string bit_ret, first_rev, second_rev;
    first_rev = reverse(first_number);
    second_rev = reverse(second_number);        
    int second_size = second_number.size();
    for(int i=0; i<second_size; i++ )
    {
        bit_ret = getTimesArithmetics(first_number, second_rev[i]);
        //cout<<"bit_ret = "<<bit_ret<<endl;
        retVector.push_back(bit_ret);
    }
    string final_ret="0";
    for(int i=0; i<second_size; i++)
    {
        string bit_shift_ret = retVector[i];
        int bit = i;
        while (bit)
        {
            bit_shift_ret = bit_shift_ret + "0";
            bit--;
        }
        final_ret = getAddArithmeticsStr(final_ret, bit_shift_ret);
    }
    //cout<<"final_ret = "<<final_ret<<endl;
    int max_length = first_number.size();
    if ((second_number.size()+1)>max_length)
        max_length = second_number.size()+1;
    if (final_ret.size()>max_length)
        max_length = final_ret.size();
    printSpace(max_length - first_number.size());
    cout<<first_number<<endl;
    printSpace(max_length - second_number.size() -1);
    cout<<"*"<<second_number<<endl;
    if(second_number.size()>1)
    {
        printSpace(max_length - second_number.size() -1);
        printBash(second_number.size() + 1);
        cout<<endl;
        for(int i=0; i<second_size; i++)
        {
            printSpace(max_length-retVector[i].size()-i);
            cout<<retVector[i]<<endl;
        }
    }
    printBash(max_length);
    cout<<endl;
    printSpace(max_length - final_ret.size());
    cout<<final_ret<<endl;
    return 0;
}


int getArithmetics(string input)
{
    
    int token_id; //1:+ 2:- 3:*
    size_t pos;
    if(input.find('+')!=string::npos)
    {
        pos = input.find('+');
        token_id = 1;
    }
    if(input.find('-')!=string::npos)
    {
        pos = input.find('-');
        token_id = 2;
    }
    if(input.find('*')!=string::npos)
    {
        pos = input.find('*');
        token_id = 3;
    }
    string first_number, second_number;
    first_number = input.substr(0, pos);
    second_number = input.substr(pos+1, input.size());
    //cout<<"first_number = "<<first_number<<", second_number = "<<second_number<<endl;
    if (token_id == 1)
        getAddArithmetics(first_number, second_number);
    else if (token_id == 2)
        getMinusArithmetics(first_number, second_number);
    else if (token_id == 3)
        getTimesArithmetics(first_number, second_number);
    return 0;
}
int main() 
{
    int taskNumber;
    cin>>taskNumber; // Read the next number
    //if ((taskNumber>0)&&(taskNumber<=TASK_NUM))
    {
        vector<string> input;
        for(int i= 0; i<taskNumber; i++) 
        {
            string str;
            cin>>str; // Read the next number
            input.push_back(str);
        }
        for(int i= 0; i<taskNumber; i++) 
        {    
            getArithmetics(input[i]);
            //cout<<endl;
        }
    }  
    
    return 0;
}
