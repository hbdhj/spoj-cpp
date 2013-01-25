/*
3934. Recaman's Sequence
7
10000
-1
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> input;
    int max = 0;
    while(n>0)
    {
        if(max<n)
            max=n;
        input.push_back(n);
        cin>>n;
    }
    vector<long long> matrix(max+1,0);
    for(int i=1;i<max+1;i++)
    {
        if(((matrix[i-1]-i)>0)&&(find(matrix.begin(),matrix.begin()+i,matrix[i-1]-i)==matrix.begin()+i))
            matrix[i] = matrix[i-1]-i;
        else
            matrix[i] = matrix[i-1]+i;
        cout<<matrix[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<input.size();i++)
    {
        cout<<matrix[input[i]]<<endl;
    }
    return 0;
}