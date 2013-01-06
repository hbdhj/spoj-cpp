#include <iostream>
#include <vector>
using namespace std;
int main()
{
    char t_N[3];
    cin.getline(t_N, 3);
    int a, tN, am, bm, c, i;
    unsigned long b;
    sscanf(t_N, "%d", &tN);
    vector<int> as;
    vector<unsigned long> bs;
    for(i=0; i<tN; i++)
    {
        char num[20];
        cin.getline(num, 20);
        sscanf(num, "%d %u", &a, &b);
        as.push_back(a);
        bs.push_back(b);
    }
    for(i=0;i<tN;i++)
    {
        am=as[i]%10;
        bm=bs[i]%4+4;
        c=1;
        while(bm--)c*=am;
        if(as[i]==0)c=0;
        else if(bs[i]==0)c=1;
        cout<<c%10<<endl;
    }
    return 0;
}
