/*
10712. Easy Calculation
Input:
1
1 1 20
Output:
19.441787
 A*x+B*sin(x)=C
*/
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

double orexp(double a, double b, double c, double x) {
    double res = double((a * x) + (b * sin(x)) - c);
    return res;
}

double dfexp(double a, double b, double x) {
    double res = a + (b * cos(x));
    return res;
}

int main() {
    int cases;
    double a, b, c, x1, x2;
    cin >> cases;
    while(cases--) {
        cin >> a >> b >> c;
        x1 = double(c / a);
        x2 = double(x1 - ((orexp(a, b, c, x1)) / (dfexp(a, b, x1))));
        x1 = x2;
        for(int i = 0; i < 100; i++) {
            x2 = double(x1 - ((orexp(a, b, c, x1)) / (dfexp(a, b, x1))));
            x1 = x2;
        }
        printf("%0.06lf\n", x2);
    }
}
