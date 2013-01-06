/* Deng Haijun 2012/12/10 9380. Connecting three towns */
#include <iostream>
#include <complex>
#include <math.h>
#define CF complex<float>
#define CF6 (complex<float>(0.5, 0.5*sqrt(float(3.0))))
#define CF30 (complex<float>(0.5, 0.5*sqrt(float(3.0))))
//M_PI
using namespace std;

float Angle(CF a, CF b, CF c)
{
    CF ac=(c-a);
    CF ab=(b-a)*CF(ac.real(),0-ac.imag());
    return arg(ab);
}
bool Obtuse(CF c1, CF c2, CF c3)
{
    float ag = Angle(c1, c2, c3);
    if((ag>(M_PI*2/3))&&(ag<(M_PI*4/3)))
        return true;
    else
        return false;
}
//This have a problem
CF getX(CF c1, CF c2, CF c3, CF c4)
{
    float x1,y1,x2,y2,x3,y3,x4,y4,x,y;
    x1=c1.real();
    y1=c1.imag();
    x2=c2.real();
    y2=c2.imag();
    x3=c3.real();
    y3=c3.imag();
    x4=c4.real();
    y4=c4.imag();
    float a,b,c,d,e,f;
    a=y1-y2;
    b=x2-x1;
    c=y1-y2;
    d=x2-x1;
    x=(((y1-y2)*x2+(x2-x1)*y2)*(x4-x3)-((y3-y3)*x4+(x4-x3)*y4)*(x2-x1))/((y1-y2)*(x4-x3)-(y3-y4)*(x2-x1));
    y=(((y1-y2)*x2+(x2-x1)*y2)*(y4-y3)-((y3-y3)*x4+(x4-x3)*y4)*(y2-y1))/((y1-y2)*(x4-x3)-(y3-y4)*(x2-x1));
    return CF(x, y);
}

CF getP(CF c1, CF c2, CF c3)
{
    float d12, d13, d23;
    if(Obtuse(c1, c2, c3))
        return c1;
    else if(Obtuse(c2, c1, c3))
        return c2;
    else if(Obtuse(c3, c2, c1))
        return c3;
    else 
    {
        float ag = Angle(c1, c2, c3);
        if(ag>(M_PI*4/3))//Switch c2, c3
        {
            CF d=c3;
            c3=c2;
            c2=d;
        }
        CF c21=(c2-c1);
        cout<<c21.real()<<", "<<c21.imag()<<endl;
        CF c31=(c3-c1);
        cout<<c31.real()<<", "<<c31.imag()<<endl;
        CF c22=c31*CF30;
        cout<<c22.real()<<", "<<c22.imag()<<endl;
        CF c32=c21*CF6;
        cout<<c32.real()<<", "<<c32.imag()<<endl;
        CF x= getX(c21, c22, c31, c32);
        cout<<x.real()<<", "<<x.imag()<<endl;
        //return getX(c21, c31, c22, c32)+c1;
        return x+c1;
    }        
}
int main()
{
    /*char test_cases_number[3];
    cin.getline (test_cases_number,3);
    int tN;*/
    CF p=getP(CF(2.0, 2.0), CF(1.0, 1.0), CF(2.0, 1.0));
    cout<<p.real()<<", "<<p.imag()<<endl;
    return 0;
}