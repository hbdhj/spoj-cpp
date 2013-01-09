/*
Sample Input
05e0
01e1
42e0
66e6
00e0
Sample Output
3
5
21
64891137
OEIS:
a(2^m+k)=1+2*k
*/

#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int n;
    vector<int> inputs;
    char line[4];
    do
    {
        scanf("%s", line);
        n=(line[0]-'0')*10+(line[1]-'0');
        while(line[3]!='0')
        {
            n*=10;
            line[3]--;
        }
        inputs.push_back(n);
    }while(n!=0);
    for(int i=0;i<inputs.size()-1;i++)
    {
        //printf("%d\n", inputs[i]);
        //int bit=0;
        int m=1;
        n=inputs[i];
        while(n>1)
        {
            n/=2;
            //bit++;
            m*=2;
        }
        printf("%d\n", (inputs[i]-m)*2+1);
    }
    return 0;
}