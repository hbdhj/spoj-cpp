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
    char task_number[3];
    cin.getline (task_number,3); // Read the next number
    int taskNumber;
    sscanf (task_number,"%d", &taskNumber);
    if ((taskNumber>0)&&(taskNumber<=100))
    {
        char strinput[EXPR_LENGTH];
        while(taskNumber) 
        {
            cin.getline (strinput,EXPR_LENGTH); // Read the next number
            string expr = strinput;
            string ret = parseStr(expr);
            cout<<ret<<endl;
            taskNumber--;
        }
    }
    return 0;
}
