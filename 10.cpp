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

char token[] = {'+', '-', '*', '/', '^'};

int lowestTokenStage(string expr)
{
    int lowestTokenStage = expr.size();
    int stage = 0;
    for(int i=0; i<expr.size(); i++)
    {
        if(expr[i]=='(')
            stage++;
        else if (expr[i]==')')
            stage--;
        for(int j=0; j<TOKEN_NUM; j++)
        {
            if(expr[i]==token[j])
            {
                if(lowestTokenStage>stage)
                    lowestTokenStage = stage;
            }
        }
    }
    return lowestTokenStage;
}

bool existRedBucket(string expr)
{
    if((expr[0]=='(')&&(expr[expr.size()-1]==')')&&(lowestTokenStage(expr)))
    {
        return true;
    }
    else
        return false;
}

string removeRedBucket(string expr)
{
    string ret = expr;
    while(existRedBucket(ret))
    {
        ret = ret.substr(1, ret.size()-2);
    }
    return ret;
}

string parseStr(string expr)
{
    if (expr.size()==1)
        return expr;
    int expr_length = expr.size();
    vector<int> deepth(expr_length, 0);
    int deep = 0;
    for(int i=0; i<expr_length; i++)
    {
        if(expr[i]=='(')
            deep++;
        else if (expr[i]==')')
            deep--;
        deepth[i]=  deep;
    }
    if(deep!=0)
    {
        cout<<"ERROR: failed to parse "<<expr<<endl;
        return "";
    }
    vector<int> token_deepth(TOKEN_NUM, expr_length+1);
    vector<int> token_pos(TOKEN_NUM, expr_length+1);
    
    for(int i=0; i<TOKEN_NUM; i++)
    {
        for(int j=0; j<expr_length; j++)
        {
            if((token_deepth[i]>deepth[j])&&(expr[j]==token[i])) // Search the token in string
            {
                token_deepth[i] = deepth[j];
                token_pos[i]= j;
            }
        }
    }
    // List the token deep
    int lowest_token_deep = expr_length+1;
    int lowest_token_pos = expr_length+1;
    int lowest_token_id = 0;
    
    for(int i=0; i<TOKEN_NUM; i++)
    {
        if(lowest_token_deep>token_deepth[i])
        {
            lowest_token_pos = token_pos[i];
            lowest_token_deep = token_deepth[i];
            lowest_token_id = i;
        }
    }
    
    return parseStr(expr.substr(lowest_token_deep, lowest_token_pos-1))
          +parseStr(expr.substr(lowest_token_pos+1, expr.size()-lowest_token_deep -lowest_token_pos -1))
          +token[lowest_token_id];
}

int main() 
{
    int taskNumber = 8;
    /*cin>>taskNumber; // Read the next number
    */
    if ((taskNumber>0)&&(taskNumber<=TASK_NUM))
    {
        vector<string> input;
        for(int i= 0; i<taskNumber; i++) 
        {
            string str;
            cin>>str; // Read the next number
            input.push_back(str);
        }
        /*input.push_back("(a+(b*c))");
        input.push_back("((a+b)*c)");
        input.push_back("(a*(b*c))");
        input.push_back("(a*(b/c)*d)");
        input.push_back("((a/(b/c))/d)");
        input.push_back("((x))");
        input.push_back("(a+b)-(c-d)-(e/f)");
        input.push_back("(a+b)+(c-d)-(e+f)");*/
        for(int i= 0; i<taskNumber; i++) 
        {    
            cout<<removeRedBucket(input[i])<<endl;
        }
    }
    return 0;
}
