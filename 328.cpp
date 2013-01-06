/* Deng Haijun 2012/12/13
*/
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

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

int main(int argc, char **argv)
{
    //cout<<"argc = "<<argc<<endl;
    if(argc!=2){
        cerr << "Error: file could not be opened" << endl;
        return 2;
    }
    ifstream indata;
    indata.open(argv[1]); // opens the file
    if(!indata) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        return 1;
    }
    vector<string> inputs;
	int lineid=0;
    while ( !indata.eof() ) { // keep reading until end-of-file
        string line;
        lineid++;
        indata >> line; // sets EOF flag if no value found
        inputs.push_back(line);
    }
    for(int i=0;i<inputs.size();i++)
    {
        if(inputs[i]=="0")
            cout<<"0"<<endl;
        else if(inputs[i]=="1")
            cout<<"1"<<endl;
        else
        {    
            string str1 = getAddArithmeticsStr(inputs[i], inputs[i]);
            string str2 = getMinusArithmetics(str1, "2");
            cout<<str2<<endl;
        }
    }
    indata.close();
	return 0;
}