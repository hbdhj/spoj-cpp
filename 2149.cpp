/*
2149. Biased Standings
Input:
2
7
noobz 1
llamas 2
Winn3rz 2
5thwheel 1
NotoricCoders 5
StrangeCase 7
WhoKnows 7
3
ThreeHeadedMonkey 1
MoscowSUx13 1
NeedForSuccess 1
Output:
5
3
Explanation:
1. noobz
2. llamas
3. Winn3rz
4. 5thwheel
5. NotoricCoders
6. WhoKnows
7. StrangeCase
*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T, N, i, j, e;
    scanf("%d",&T);
    vector<vector<int> > expectedLists;
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        vector<int> expectedList(N, 0);
        for(j=0;j<N;j++)
        {
            char name[30];
            scanf("%s %d",name, &e);
            expectedList[j]=e;
        }
        expectedLists.push_back(expectedList);
    }    
}