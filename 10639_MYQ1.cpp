/*
TASK: The Blind Passenger
      W  A   A  M  W
      01 
1     02 03  04 05 06 
2     11 10  09 08 07 
3     12 13  14 15 16
4     21 20  19 18 17
5     22 ............ 
Input:
3 
1 
2 
3
Output:
poor conductor 
1 W L 
1 A L
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i, t;
    unsigned long long int n;
    vector<unsigned long long int> inputs;
    scanf("%d", &t);
    for(i=0;i<t;i++)
    {
        scanf("%llu", &n);
        inputs.push_back(n);
    }
    for(i=0;i<t;i++)
    {
        n=inputs[i];
        if(n==1)
            printf("poor conductor\n");
        else
        {
            unsigned long long int rowNum=(n-2)/5+1;
            int seatId=(n-2)%10;
            char sId,direction;
            switch(seatId)
            {
                case 0:
                    sId='W';
                    direction='L';
                    break;
                case 1:
                    sId='A';
                    direction='L';
                    break;
                case 2:
                    sId='A';
                    direction='R';
                    break;
                case 3:
                    sId='M';
                    direction='R';
                    break;
                case 4:
                    sId='W';
                    direction='R';
                    break;   
                case 5:
                    sId='W';
                    direction='R';
                    break;
                case 6:
                    sId='M';
                    direction='R';
                    break;
                case 7:
                    sId='A';
                    direction='R';
                    break;
                case 8:
                    sId='A';
                    direction='L';
                    break;
                case 9:
                    sId='W';
                    direction='L';
                    break;                     
            }
            printf("%llu %c %c\n", rowNum, sId, direction);
        }
    }
    return 0;
}
