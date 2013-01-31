/*
7742. Onotole needs your help
Just use xor
Input:
3
1
8
1
Output:
8
*/
#include <stdio.h>
using namespace std;

int main() {
    int N;
    int tmp;
    int X = 0;

    scanf("%d", &N);
    while(N--) {
        scanf("%d", &tmp);
        X = X ^ tmp;    //xor
    }
    printf("%d\n", X);
    return 0;
}