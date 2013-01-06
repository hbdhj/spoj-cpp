/*
Input:
1000 37
999 37
10000 370
10001 370
-1 -1

Output:
Y
N
Y
N
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i,w;
    vector<char> output;
    scanf("%d %d",&i,&w);
    while((i!=-1)&&(w!=-1))
    {
        if(i*37==w*1000)
        output.push_back('Y');
        else
        output.push_back('N');        
        scanf("%d %d",&i,&w);        
    }
    for(i=0;i<output.size();i++)
        printf("%c\n", output[i]);
}