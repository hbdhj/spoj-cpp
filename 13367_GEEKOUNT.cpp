/*
TASK: EVEN COUNT
Sample Input:
2
2 12
4 23
Sample Output:
6
12
*/

#include <iostream>
#include <vector>
using namespace std;

// Check the single number
int f(int n)
{
    int ret=1;
    int m=n;
    while(n)
    {
        ret*=n%10;
        if(ret%2==0)
            return 0;
        n=n/10;
    }
    return ret;
}

// Check number from zero to n
unsigned long long even_n(int n, vector<unsigned long long> even_num)
{
    // get the number of digits the n, 123 -> 3
    int bit=0;
    int m=n;
    while (m) {
        bit++;
        m=m/10;
    }
    // get vector of digits of n, 123 -> 3,2,1
    m=n;
    vector<int> bits(bit,0);
    unsigned long long base=1;
    for (int i=0; i<bit; i++) {
        bits[i]=m%10;
        m=m/10;
        base*=10;
    }
    // get the ret
    unsigned long long ret=0;
    m=n;
    int i;
    for (i=bit-1; i>0; i--) {
        base=base/10;
        if(bits[i])
        {
            int even = (bits[i]-1)/2;
            int odd = bits[i]-even;
            ret+=even*base;             //add base, e.g. 334 -> 100
            ret+=odd*even_num[i]+odd;   //add odd num, e.g. 334 -> 70*2
            m-=bits[i]*base;            
            if(m==0)
                break;
            if(bits[i]%2==0)
            {
                return ret+m+1;
                break;
            }
        }
    }
    ret+=bits[0]-(bits[0]+1)/2+1;
    return ret;
}

// check the num from l to r
unsigned long long even(int l, int r, vector<unsigned long long> even_num)
{
    unsigned long long rl,rr;
    rl=even_n(l,even_num);
    rr=even_n(r,even_num);
    if(f(l)%2)
        return rr-rl;
    else
        return rr-rl+1;
}

int main()
{
    //4 69 844 9219 96094
    vector<unsigned long long> even_num(11, 0);
    even_num[0]=1;
    even_num[1]=4;
    unsigned long long rem=5;
    unsigned long long base=10;
    for(int i=2;i<11;i++)
    {
        base*=10;
        rem*=5;
        even_num[i]=base-rem-(base/10-even_num[i-1]);
    }
    
    int i,t;
    scanf("%d", &t);
    vector<int> ls(t,0);
    vector<int> rs(t,0);
    for(i=0;i<t;i++)
        scanf("%d %d", &ls[i], &rs[i]);
    for(i=0;i<t;i++)
        printf("%lld\n", even(ls[i], rs[i], even_num));
    return 0;
}
