/*
TASK: Tic-Tac-Toe ( II )
Input:
XXXOO.XXX
XOXOXOXOX
OXOXOXOXO
XXOOOXXOX
XO.OX...X
.XXX.XOOO
OOXXXOOXO
XX.OOO..X
X.OOX...X
XXO.XOX.O
XXOOOXXOX
end

Output:
invalid
valid
invalid
valid
valid
invalid
invalid
valid
valid
invalid
valid
*/
#include <iostream>
#include <vector>

using namespace std;

int num(string m, char c)
{
    int ret=0;
    for(int i=0;i<m.length();i++)
        if(m[i]==c)
            ret++;
    return ret;
}
bool success(string m, char c)
{
    for(int i=0;i<3;i++)
        if((m[i*3]==c)&&(m[i*3+1]==c)&&(m[i*3+2]==c))
            return true;
    for(int i=0;i<3;i++)
        if((m[i]==c)&&(m[i+3]==c)&&(m[i+6]==c))
            return true;
    if((m[0]==c)&&(m[4]==c)&&(m[8]==c))
        return true;
    if((m[2]==c)&&(m[4]==c)&&(m[6]==c))
        return true;
    return false;
}
bool isOK(string m)
{
    int nO=num(m, 'O');
    int nX=num(m, 'X');
    //printf("nO = %d, nX = %d\n", nO, nX);
    /*
    if(nO>nX)
        return false;
    else if(nO==nX)
    {
        //Should No success X
        if(success(m, 'X'))
            return false;    
    }
    else
    {
        if(success(m, 'O'))
            return false;
        if(nX>nO+1)
            return false;
    }*/
    if(nO==nX) //O win
    {
        if(success(m, 'X'))
            return false;
        if(success(m, 'O'))
            return true;
    }
    else if(nO==(nX-1)) //O win
    {
        if(success(m, 'O'))
            return false;    
        if(success(m, 'X'))
            return true;
        if((nX+nO)==9)
            return true;
    }
    return false;
}

int main()
{
    char m[10];
    scanf("%s", m);
    string str=m;
    vector<string> inputs;
    while(str.find("end")== string::npos)
    {
        inputs.push_back(str);
        scanf("%s", m);
        str=m;
    }
    for(int i=0;i<inputs.size();i++)
    {
        if(isOK(inputs[i]))
            printf("valid\n");
        else
            printf("invalid\n");
    }
    return 0;
}
