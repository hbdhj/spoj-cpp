#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
float S(int r, float h)
{
    return r*r*(M_PI-asin(h/r));
}
int main()
{
    int tN,x1,y1,r1,x2,y2,r2,i,xd,yd;
    float rt,d,s,p,h;
    cin>>tN;
    vector<float> rts;
    for(int i=0;i<tN; i++)
    {
        cin>>x1;
        cin>>y1;
        cin>>r1;
        cin>>x2;
        cin>>y2;
        cin>>r2;
        xd=x2-x1;
        yd=y2-y1;
        d=sqrt(float(xd*xd-yd*yd));
        p=(d+r1+r2)/2;
        s=sqrt(2*(p-d)*(p-r1)*(p-r2)*p);
        h=s/d;
        cout<<d<<", "<<p<<", "<<s<<", "<<h<<endl;
        rts.push_back(s+S(r1,h)+S(r2,h));
    }
    for(int i=0;i<tN; i++)
    {        
        printf("%.2f\n",rts[i]);
    }
    return 0;
}