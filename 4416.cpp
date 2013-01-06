#include <iostream>
#include <complex>
#include <vector>

using namespace std;

#define PI 3.14159265
//#define PI 3.141592653
//#define PI 3.1415926535
#define COMPLEX complex<float>

int getTimesFromStr(string input)
{
    int hours, minutes, seconds;
    sscanf(input.c_str(), "%d:%d:%d", &hours, &minutes, &seconds);
    //cout<<"hours = "<<hours<<", minutes = "<<minutes<<", seconds = "<<seconds<<endl;
    return hours*3600+minutes*60+seconds;
}

COMPLEX getG(COMPLEX a, COMPLEX b, int ag, int bg)
{
    COMPLEX ret = COMPLEX((ag*(a.real())+bg*(b.real()))/(ag+bg), (ag*(a.imag())+bg*(b.imag()))/(ag+bg));
    //cout<<"a.real() = "<<a.real()<<", a.imag() = "<<a.imag()<<", ag = "<<ag<<endl;
    //cout<<"b.real() = "<<b.real()<<", b.imag() = "<<b.imag()<<", bg = "<<bg<<endl;
    //cout<<"ret.real() = "<<ret.real()<<", ret.imag() = "<<ret.imag()<<endl;
    return ret;
    //return COMPLEX((ag*(a.real())+bg*(b.real()))/(ag+bg), (ag*(a.imag())+bg*(b.imag()))/(ag+bg));
}

COMPLEX getHG(float l, int time)
{
    float angel = float(time)*PI/(3600*6);
    return COMPLEX(l*sin(angel), l*cos(angel));
}

COMPLEX getMG(float l, int time)
{
    float angel = float(time)*PI/1800;
    return COMPLEX(l*sin(angel), l*cos(angel));
}

COMPLEX getSG(float l, int time)
{
    float angel = float(time)*PI/30;
    //cout<<"angel = "<<angel<<", sin(angel) = "<<sin(angel)<<", cos(angel) ="<<cos(angel)<<endl;
    return COMPLEX(l*sin(angel), l*cos(angel));
}

float getD(int lh, int lm, int ls, int gh, int gm, int gs, int time)
{
    COMPLEX hG0 = getHG(float(lh)/2, time);
    COMPLEX mG0 = getMG(float(lm)/2, time);
    COMPLEX sG0 = getSG(float(ls)/2, time);
    COMPLEX hmG0 = getG(hG0, mG0, gh, gm);
    COMPLEX hmsG0 = getG(hmG0, sG0, gh+gm, gs);
    COMPLEX hG1 = getHG(float(lh)/2, time+1);
    COMPLEX mG1 = getMG(float(lm)/2, time+1);
    COMPLEX sG1 = getSG(float(ls)/2, time+1);
    COMPLEX hmG1 = getG(hG1, mG1, gh, gm);
    COMPLEX hmsG1 = getG(hmG1, sG1, gh+gm, gs);
    return abs(hmsG1-hmsG0);
}

float getD(int lh, int lm, int ls, int gh, int gm, int gs, int start, int end)
{
    float ret = 0;
    /*float reth = 0;
    if((end - start)>3600)
    {
        for(int i = start; i<(start+3600); i++)
            reth += getD(lh, lm, ls, gh, gm, gs, i);
        ret = reth*int((end - start)/3600);
        int new_start = start + int((end - start)/3600)*3600;
        for(int i = new_start; i<end; i++)
        {
            ret += getD(lh, lm, ls, gh, gm, gs, i);
        }
    }
    else*/
    {
        for(int i = start; i<end; i++)
        {
            ret += getD(lh, lm, ls, gh, gm, gs, i);
        }
    }
    return ret;
}

int main()
{
    vector<string> inputs;
    while(1)
    {
        char in[40];
        cin.getline (in, 40); // Read the next number
        if((in[0]=='-')&&(in[1]=='1'))break;
        string str=in;
        inputs.push_back(str);
    }
    for(int i =0; i<inputs.size(); i++)
    {
        char start[10], end[10];
        int hl, ml, sl, hg, mg, sg;
        sscanf(inputs[i].c_str(), "%d %d %d %d %d %d %s %s", &hl, &ml, &sl, &hg, &mg, &sg, start, end);
        int startsec, endsec;
        startsec = getTimesFromStr(start);
        endsec = getTimesFromStr(end);
        //cout<<inputs[i]<<endl;
        printf("%.2f\n", getD(hl, ml, sl, hg, mg, sg, startsec, endsec));
    }
    //printf("%.2f\n",getD(3, 4, 5, 1, 1, 1, 9*3600, 18*3600));
    return 0;
}
