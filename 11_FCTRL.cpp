/*
 * 2012/12/01
 */
#include <iostream>
#include <vector>

using namespace std; 

#define TASK_NUM 1000000

long getFactorialZero(long input)
{
    long fivetime = 5;
    long num = 0;
    while (input >= fivetime)
    {
        num += input/fivetime;
        fivetime *=5; 
    }
    return num;
}

int main() 
{
    long taskNumber;
    cin>>taskNumber; // Read the next number
    if ((taskNumber>0)&&(taskNumber<=TASK_NUM))
    {
        vector<long> input;
        for(long i= 0; i<taskNumber; i++) 
        {
            long str;
            cin>>str; // Read the next number
            input.push_back(str);
        }
        for(long i= 0; i<taskNumber; i++) 
        {    
            cout<<getFactorialZero(input[i])<<endl;
        }
    }
    return 0;
}