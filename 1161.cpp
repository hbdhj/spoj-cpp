/*
1161. Tic-Tac-Toe ( I )
Input:
6
X.O
OO.
XXX

O.X
XX.
OOO

XXO 
OOX 
OXX 

XXX 
OO. 
..O 

XXX 
OOO 
... 

0X0
XXX
0X0

Output:
yes
no
no
no
no
no
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
    }
    return true;
}

int main()
{
    /*//case 1
    if(isOK("X.OOO.XXX"))
        printf("correct!\n");
    else    
        printf("wrong!\n");
    //case 2
    if(isOK("O.XXX.OOO"))
        printf("wrong!\n");
    else    
        printf("correct!\n");
    //case 3
    if(isOK("XXOOOXOXX"))
        printf("wrong!\n");
    else    
        printf("correct!\n");
    //case 4
    if(isOK("XXXOO...O"))
        printf("wrong!\n");
    else    
        printf("correct!\n");
    //case 5
    if(isOK("XXXOOO..."))
        printf("wrong!\n");
    else    
        printf("correct!\n");*/
    int i, tN;
    scanf("%d", &tN);
    vector<string> inputs(tN);
    for(i=0;i<tN;i++)
    {
        char line[3];
        scanf("%s", line);
        inputs[i]=line;
        scanf("%s", line);
        inputs[i]+=line;
        scanf("%s", line);
        inputs[i]+=line;        
    }
    for(i=0;i<tN;i++)
    {
        //printf("%s\n", inputs[i].c_str());
        if(isOK(inputs[i]))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}