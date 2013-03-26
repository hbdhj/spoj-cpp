/*
partial 5536. Physics Grade
Input:
3
100 89
75 75
100 72
Output:
B
90 - 100 = A
80 - 89 = B
70 - 79 = C
60 - 69 = D
0 - 59 = F (Heaven forbid!)
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int i, n, pi, si;
    scanf("%d", &n);
    int sum_pi=0;
    int sum_si=0;
    for(i=0;i<n;i++)
    {
        scanf("%d %d", &pi, &si);
        sum_pi+=pi;
        sum_si+=si;        
    }
    
    float grade=float(sum_si)/sum_pi*100;
    if(grade>=90)
        printf("A\n");
    else if(grade>=80)
        printf("B\n");
    else if(grade>=70)
        printf("C\n");
    else if(grade>=60)
        printf("D\n");
    else
        printf("F\n");
    
    return 0;
} 