/*
12448. HOW MANY GAMES
Sample Input:
5
5
5.5
30.25
30.65
40.34
Sample Output:
1
2
4
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t,i;
    scanf("%d",&t);
    //vector<int> inputs(t,0);
    vector<string> inputs(t);
    for(i=0;i<t;i++)
    {
        //float f;
        //scanf("%f", &f);
        char num[14];
        scanf("%s", num);
        inputs[i]=num;
    }
    for(i=0;i<t;i++)
    {
        size_t pos=inputs[i].find('.');
        if(pos==string::npos)
            printf("1\n");
        else
        {
            int right=0;
            int base=1;
            int j=pos+1;
            while(j<inputs[i].length())
            {
                right=right*10+inputs[i][j]-'0';
                base*=10;
                j++;
            }
            if(base%right==0)
                printf("%d\n",base/right);
            else
            {
                while((right%2==0)&&(base%2==0))
                {
                    right=right/2;
                    base=base/2;
                }
                while((right%5==0)&&(base%5==0))
                {
                    right=right/5;
                    base=base/5;
                }
                printf("%d\n",base);
            }    
        }
    }
    return 0;
}
