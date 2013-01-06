/* Deng Haijun 2012/12/13
*/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int compare(string str1, string str2)
{
    int ret =0;
    //cout<<str1.length()<<", "<<str2.length()<<endl;
    if(str1.length()>str2.length())
    {
        ret = 1;
    }
    else if(str1.length()<str2.length())
    {
        ret = -1;
    }
    else if(str1.length()==str2.length())
    {
        ret = 0;
        for(int i=0;i<str1.length();i++)
        {
            if(str1[i]>str2[i])
            {
                ret=1;
                break;
            }
            else if(str1[i]<str2[i])
            {
                ret=-1;
                break;
            }
        }
    }    
    //cout<<"compare("<<str1<<", "<<str2<<") = "<<ret<<endl;
    return ret;
}
string reverse(string input)
{
    string ret = input;
    int size = input.length();
    for (int i=0;i<size;i++)
        ret[i] = input[size-1-i];
    return ret;
}

string getAddArithmeticsStr(string first_number, string second_number)
{
    string big, small, ret;
    if (first_number.length()>second_number.length())
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
    int small_size = small.length();
    int big_size = big.length();
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
    while ((ret[0]=='0')&&(ret.length()>1))
        ret=ret.substr(1, ret.length()-1);
    
    return ret;
}

string getMinusArithmetics(string first_number, string second_number)
{
    string first_rev, second_rev, ret;
    first_rev = reverse(first_number);
    second_rev = reverse(second_number);        
    int second_size = second_number.length();
    int first_size = first_rev.length();
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
        ret=ret.substr(1, ret.length()-1);
    return ret;
}

string plus_4190(string str1, string str2)
{
    string newStr1, newStr2;
    if(str1[0]=='-')
    {
        newStr1 = str1.substr(1,str1.length());
    }
    if(str2[0]=='-')
    {
        newStr2 = str2.substr(1,str2.length());
    }
    //cout<<str1<<", "<<str2<<", "<<newStr1<<", "<<newStr2<<endl;
    if((str1[0]!='-')&&(str2[0]!='-'))
        return getAddArithmeticsStr(str1, str2);
    else if((str1[0]=='-')&&(str2[0]!='-'))
    {
        if(compare(newStr1, str2)==1)
            return "-"+getMinusArithmetics(newStr1, str2);  
        else if(compare(newStr1, str2)==0)
            return "0";
        else if(compare(newStr1, str2)==-1)
            return getMinusArithmetics(str2, newStr1);          
    }
    else if((str1[0]!='-')&&(str2[0]=='-'))
    {
        if(compare(newStr2, str1)==1)
            return "-"+getMinusArithmetics(newStr2, str1);  
        else if(compare(newStr2, str1)==0)
            return "0";
        else if(compare(newStr2, str1)==-1)
            return getMinusArithmetics(str1, newStr2);          
    }
    else if((str1[0]=='-')&&(str2[0]=='-'))
    {
        return "-"+getAddArithmeticsStr(newStr2, newStr1);
    }
}

int main(int argc, char **argv)
{
    //cout<<"argc = "<<argc<<endl;
    string str1, str2;
    cin>>str1;
    cin>>str2;    
    /*cout<<plus_4190("1000","-999")<<endl;
    cout<<plus_4190("1","1")<<endl;
    cout<<plus_4190("1","-1")<<endl;
    cout<<plus_4190("-1","1")<<endl;
    cout<<plus_4190("-1","-1")<<endl;
    cout<<plus_4190("12","13")<<endl;
    cout<<plus_4190("12","-13")<<endl;
    cout<<plus_4190("-12","13")<<endl;
    cout<<plus_4190("-12","-13")<<endl;*/
    cout<<plus_4190(str1,str2)<<endl;
    return 0;
}