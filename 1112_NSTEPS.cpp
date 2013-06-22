/*
 * 2012/12/09
 TASK: Number Steps
 */
#include <iostream>
#include <vector>


using namespace std; 

#define EXPR_LENGTH 20
#define CASE_LENGTH 6

int get(string input)
{
    int n1, n2;
    //cout<<input<<endl;
    sscanf (input.c_str(),"%d %d", &n1, &n2);
    if(n1==n2)
    {
        if(n1%2)
        {
            cout<<2*n1-1<<endl;
        }
        else
        {
            cout<<2*n1<<endl;
        }
    }
    else if ((n1-n2)==2)
    {
        if(n1>=2)
        {
            if(n1%2)
            {                
                cout<<2*n1-3<<endl;
            }
            else
            {
                cout<<2*n1-2<<endl;
            }
        }
        else
        {
            cout<<"No Number"<<endl;
        }
    }
    else
        cout<<"No Number"<<endl;
    return 0;
}
int main() 
{
    char case_number[CASE_LENGTH];
    cin.getline (case_number,CASE_LENGTH); // Read the next number
    int caseNumber;
    sscanf (case_number,"%d", &caseNumber);
    vector<string> inputs;
    while (caseNumber>0)
    {
        //cout<<"caseNumber ="<<caseNumber<<endl;
        char input[EXPR_LENGTH];
        cin.getline (input, EXPR_LENGTH); // Read the next number
        string inp = input;
        inputs.push_back(inp);        
        caseNumber--;
    }
    for(int i = 0; i<inputs.size(); i++)
        get(inputs[i]);
    return 0;
}
