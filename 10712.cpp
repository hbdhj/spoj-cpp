/*
10712. Easy Calculation
Input:
1
1 1 20
Output:
19.441787
*/

#include <cstdio>
#include <vector>

using namespace std;

void Calculation(int A, int B, int C)
{
    float min=float(C-B)/A;
    float max=float(C-B)/A;
    printf("%.6f, %.6f\n", min, max);
}

int main()
{
    int t, n, i, a[50];
    scanf("%d", &t);
    vector<int> inputs(3*t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d %d", &inputs[i*3],&inputs[i*3+1],&inputs[i*3+2]);
    }
    for(i=0;i<t;i++)
    {
        Calculation(inputs[i*3],inputs[i*3+1],inputs[i*3+2]);
    }
    
    return 0;
}