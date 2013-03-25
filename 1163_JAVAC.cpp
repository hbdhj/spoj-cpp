/*Deng Haijun 2012/12/14 1163. Java vs C ++

Input:
long_and_mnemonic_identifier
anotherExample
i
bad_Style

Output:
longAndMnemonicIdentifier
another_example
i
Error!
*/

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int checkCOrJava(string str)
{
    if((str[0]=='_')||((str[0]>='A')&&(str[0]<='Z')))
    {
        cout<<"Error!"<<endl;
        return 0;
    }
    bool isCStyle, isJavaStyle;
    isCStyle = false;
    isJavaStyle = false;
    int nCapNum=0;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i]=='_')
            isCStyle = true;
        if((str[i]>='A')&&(str[i]<='Z'))
        {
            isJavaStyle = true;
            nCapNum++;
        }    
    }
    /*if(isCStyle)
        cout<<str<<" is C style"<<endl;
    if(isJavaStyle)
        cout<<str<<" is Java style"<<endl;*/
    if(isCStyle&&isJavaStyle)
    {
        cout<<"Error!"<<endl;
    }
    else if((!isCStyle)&&(!isJavaStyle))
    {
        cout<<str<<endl;    
    }
    else if(isCStyle)
    {
        //cout<<str<<" is C style"<<endl;
        string newStr=str;
        int dec = 0;
        int newlengh=0;
        for(int i=0; i<str.length(); i++)
        {
            if(str[i]=='_')
            {
                dec++;
                i++;
                newStr[i-dec]=str[i]-'a'+'A';
            }
            else 
                newStr[i-dec]=str[i];
        }
        newStr = newStr.substr(0, str.length()-dec);
        cout<<newStr<<endl;
    }
    else if(isJavaStyle)
    {
        //cout<<str<<" is Java style"<<endl;
        string newStr(str.length()+nCapNum, '_');
        int inc = 0;
        for(int i=0; i<str.length(); i++)
        {
            if((str[i]>='A')&&(str[i]<='Z'))
            {
                inc++;
                newStr[i+inc]=str[i]-'A'+'a';
            }
            else 
                newStr[i+inc]=str[i];
        }
        cout<<newStr<<endl;
    }
    return 0;
}
int main(int argc, char **argv)
{
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
        //cout<<inputs[i]<<endl;
        checkCOrJava(inputs[i]);
    }
    return 0;
}

