#include <iostream>
#include <vector>
#include <math.h>
#define LINE_LENGTH 30
using namespace std;
struct point
{
    int h;
    int a;
    int r;
};

struct cylinder
{
    int r;
    int h;
};

struct testCase
{
    cylinder c;
    point p1;
    point p2;
};

int checkPoint(cylinder &c, point & p)
{
    cout<<"c.h = "<<c.h<<", c.r = "<<c.r<<"; p.h = "<<p.h<<", p.r = "<<p.r<<endl;
    if((c.h==p.h)&&(c.r==p.r))
        cout<<"point is on the top ring"<<endl;
    else if((0==p.h)&&(c.r==p.r))
        cout<<"point is on the bottom ring"<<endl;
    else if(c.h==p.h)
        cout<<"point is on the top side"<<endl;
    else if(p.h==0)
        cout<<"point is on the bottom side"<<endl;    
    else if(c.r==p.r)
        cout<<"point is on the side"<<endl;
    else
        cout<<"ERROR"<<endl;
    return 0;
}
float getResult(testCase& t)
{
    checkPoint(t.c, t.p1);
    checkPoint(t.c, t.p2);
    if ((t.p1.r==t.c.r)&&(t.p2.r==t.c.r)&&(t.p2.h!=t.p1.h))
    {
        //Side
        int hD=t.p1.h-t.p2.h;
        int aD=t.p1.a-t.p2.a;
        if((aD<-180)||(aD>180))
            aD=t.p2.a-t.p1.a;
        float RD=float(t.c.r)*M_PI*float(aD)/180;
        return sqrt(RD*RD+float(hD*hD));
    }
    else if(((t.p2.h==0)||(t.p2.h==t.c.h))&&(t.p2.h==t.p1.h))
    {
        //round plane
        if((aD<-180)||(aD>180))
            aD=t.p2.a-t.p1.a;
        float AD=M_PI*float(aD)/180;
        float X2=p2.r*cos(AD);
        float Y2=p2.r*sin(AD);
        return sqrt((X2-p1.r)*(X2-p1.r)+Y2*Y2);
    }
    else if((t.p2.h==0)&&(t.p1.h==t.c.h)&&(t.p2.r<t.c.r)&&(t.p1.r<t.c.r))
    {
    
    }
    else if((t.p2.h==0)&&(t.p1.h==t.c.h)&&(t.p2.r<t.c.r)&&(t.p1.r<t.c.r))
    {
    }
    return 0.0;
}

int main()
{
    char t_N[5];
    cin.getline(t_N, 5);
    int tN;
    sscanf(t_N, "%d", &tN);
    vector<testCase> tv;
    for(int i = 0; i<tN; i++)
    {
        char input[LINE_LENGTH];
        cin.getline(input, LINE_LENGTH);
        testCase t;
        sscanf(input, "%d %d", &(t.c.r), &(t.c.h));
        cout<<"t.c.r = "<<t.c.r <<", t.c.h = "<<t.c.h<<endl;
        cin.getline(input, LINE_LENGTH);
        sscanf(input, "%d %d %d", &(t.p1.h), &(t.p1.a), &(t.p1.r));
        cout<<"t.p1.h = "<<t.p1.h <<", t.p1.a = "<<t.p1.a<<", t.p1.r = "<<t.p1.r<<endl;
        cin.getline(input, LINE_LENGTH);
        sscanf(input, "%d %d %d", &(t.p2.h), &(t.p2.a), &(t.p2.r));
        cout<<"t.p2.h = "<<t.p2.h <<", t.p2.a = "<<t.p2.a<<", t.p2.r = "<<t.p2.r<<endl;
        tv.push_back(t);
    }
    for(int i = 0; i<tN; i++)
    {
        cout<<getResult(tv[i])<<endl;
    }
}