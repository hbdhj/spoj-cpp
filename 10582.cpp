/*
10582. subarrays
Input:
9
1  2  3  1  4  5  2  3  6
3
Output:
3 3 4 5 5 5 6
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, k, a, i, j, max, sec, max_pos, sec_pos;
    cin>>n;
    vector<int> inputs;
    for(i=0;i<n;i++)
    {
        cin>>a;
        inputs.push_back(a);
    }
    cin>>k;
    /*for(i=k;i<=n;i++)
    {
        max = 0;
        for(j=i-k;j<i;j++)
        {
            if(inputs[j]>max)
                max=inputs[j];
        }
        cout<<max<<" ";
    }*/
    if(k==1)
    {
        for(i=0;i<n-1;i++)
            cout<<inputs[i]<<" ";
        cout<<inputs[n-1]<<endl;
    }
    else
    {
        max = 0;
        for(i=0;i<=n;i++)
        {
            if(i<k)
            {
                if(inputs[i]>max)
                {
                    max=inputs[i];
                    max_pos=i;
                }
            }
            else
            {
                cout<<max<<" ";
                if(max_pos<i-k)
                {
                    max=0;
                    for(j=i-k;j<i;j++)
                    {
                        if(inputs[j]>max)
                        {
                            max=inputs[j];
                            max_pos=j;
                        }
                    }
                }
                else
                {
                    if(inputs[i]>max)
                    {
                        max=inputs[i];
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}