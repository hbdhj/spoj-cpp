/*
 * 2012/11/28
 */
#include  <iostream>
#include <math.h>
#include <vector>

using namespace std; 

#define TASK_NUM 100
#define EXPR_LENGTH 400
#define TOKEN_NUM 5

bool isPalindrome(string input)
{
    int inputStrLength = input.size();
    int CheckLength = inputStrLength/2;
    //cout<<"inputStrLength = "<<inputStrLength<<", CheckLength = "<<CheckLength<<endl;
    for (int i=0; i<CheckLength; i++ )
    {
        //cout<<"Check input["<<i<<"] "<< input[i] <<" and input["<<inputStrLength-i-1<<"] "<< input[inputStrLength-i-1] <<endl;
        if(input[i]!=input[inputStrLength-i-1])
            return false;
    }
    return true;
}

bool allNine(string input)
{
    int inputStrLength = input.size();
    for (int i=0; i<inputStrLength; i++ )
    {
        if(input[i]!='9')
            return false;
    }
    return true;
}

string getNextPalindrome(string input)
{
    string ret = input;
    int inputStrLength = input.size();
    int CheckLength = inputStrLength/2;
    // if all char are '9', e.g. 9999
    if (allNine(input))
    {
        int inputStrLength = input.size();
        ret[0] = '1';
        for (int i=1; i<inputStrLength; i++ )
        {
            ret[i] = '0';
        }
        return ret + "1";
    }
    //     
    if(isPalindrome(ret))
    {
        if(inputStrLength%2)
        {
            if(ret[CheckLength]!='9')
            {
                ret[CheckLength]++;
                return ret;
            }    
        }
        else
        {
            if(ret[CheckLength]!='9')
            {
                ret[CheckLength]++;
                ret[CheckLength-1]++;
                return ret;
            } 
        }
    }
    while(isPalindrome(ret)==false)
    {
        //do some change
        for (int i=0; i<CheckLength; i++ )
        {
            if(ret[i]>ret[inputStrLength-i-1])
                ret[inputStrLength-i-1] = ret[i];
            else if (ret[i]<ret[inputStrLength-i-1])
            {
                if(ret[inputStrLength-i-2]!='9')
                {
                    ret[inputStrLength-i-1] = ret[i];
                    ret[inputStrLength-i-2]++;
                }
                else
                {
                    int cur = inputStrLength-i-2;
                    while(ret[cur]=='9')
                    {
                        ret[cur]='0';
                        cur--;                        
                    }
                    ret[cur]++;
                }
            }
            //cout<<ret<<endl;
        }
    }
    return ret;
}
int main() 
{
    int taskNumber;
    cin>>taskNumber; // Read the next number
    if ((taskNumber>0)&&(taskNumber<=TASK_NUM))
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
            //string expr = inputStr[i];
            //string ret = parseStr(expr);
            cout<<getNextPalindrome(input[i])<<endl;
        }
    }
    /*
    if(isPalindrome("1"))
        cout<<"1 is Palindrom"<<endl;
    else
        cout<<"1 is NOT Palindrom"<<endl;
    if(isPalindrome("10"))
        cout<<"10 is Palindrom"<<endl;
    else
        cout<<"10 is NOT Palindrom"<<endl;
    if(isPalindrome("11"))
        cout<<"11 is Palindrom"<<endl;
    else
        cout<<"11 is NOT Palindrom"<<endl;
    if(isPalindrome("99"))
        cout<<"99 is Palindrom"<<endl;
    else
        cout<<"99 is NOT Palindrom"<<endl;   
    if(isPalindrome("123"))
        cout<<"123 is Palindrom"<<endl;
    else
        cout<<"123 is NOT Palindrom"<<endl;   
    if(isPalindrome("121"))
        cout<<"121 is Palindrom"<<endl;
    else
        cout<<"121 is NOT Palindrom"<<endl;   
    if(isPalindrome("1231"))
        cout<<"1231 is Palindrom"<<endl;
    else
        cout<<"1231 is NOT Palindrom"<<endl;   
    if(isPalindrome("1331"))
        cout<<"1331 is Palindrom"<<endl;
    else
        cout<<"1331 is NOT Palindrom"<<endl;   
    */
    /*cout<<"The next Palindrome of 9 is "<<getNextPalindrome("9")<<endl;
    cout<<"The next Palindrome of 123 is "<<getNextPalindrome("123")<<endl;
    cout<<"The next Palindrome of 191 is "<<getNextPalindrome("191")<<endl;
    cout<<"The next Palindrome of 123321 is "<<getNextPalindrome("123321")<<endl;
    cout<<"The next Palindrome of 808 is "<<getNextPalindrome("808")<<endl;
    cout<<"The next Palindrome of 2133 is "<<getNextPalindrome("2133")<<endl;
    cout<<"The next Palindrome of 999 is "<<getNextPalindrome("999")<<endl;
    cout<<"The next Palindrome of 899 is "<<getNextPalindrome("899")<<endl;
    cout<<"The next Palindrome of 9999 is "<<getNextPalindrome("9999")<<endl;
    cout<<"The next Palindrome of 8999 is "<<getNextPalindrome("8999")<<endl;*/
    return 0;
}
