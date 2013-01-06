/*
 * 2012/11/29
 */
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
#include <complex>

using namespace std;

#define TASK_NUM 10000
#define COMPLEX complex<float> 

COMPLEX get(COMPLEX a, COMPLEX b)
{
    if(a.real()==b.real())
    {
        return COMPLEX(a.real(), abs(a)>abs(b)?abs(a.imag()):abs(b.imag()));
    }
    /*if(a.imag()==b.imag())
    {
        return COMPLEX((a.real()+b.real())/2, abs(COMPLEX((b.real()-a.real())/2, a.imag())));
    }*/
    else
    {
        float x = (b.real()*b.real()+b.imag()*b.imag()-a.real()*a.real()-a.imag()*a.imag())/(b.real()-a.real())/2;
        float minX, maxX, minY, maxY;
        minX = b.real()>a.real()?a.real():b.real();
        maxX = b.real()>a.real()?b.real():a.real();
        minY = b.real()>a.real()?a.imag():b.imag();
        maxY = b.real()>a.real()?b.imag():a.imag();
        if(x<minX)
        {
            return COMPLEX(minX, abs(minY));
        }
        else if(x>maxX)
        {
            return COMPLEX(maxX, abs(maxY));
        }
        else{
            COMPLEX m = COMPLEX(x, 0);
            return COMPLEX(x, abs(a-m));
        }
    }
}

int main() 
{
    char home_number[7];
    cin.getline (home_number,7); // Read the next number
    int homeNumber;
    sscanf (home_number,"%d", &homeNumber);    
    vector<COMPLEX > outputs;
    while (homeNumber!=0)
    {
        //string hN = home_number;
        //input.push_back(hN);
        COMPLEX r[2];
        COMPLEX ret;
        for(int i= 0; i<homeNumber; i++) 
        {            
            char in[30];
            cin.getline (in, 30); // Read the next home location
            
            float c_i_r, c_i_i;
            sscanf (in,"%f %f", &c_i_r, &c_i_i);
            COMPLEX c_i(c_i_r, c_i_i);
            
            if(i<2)
                r[i]=c_i;
            if (i==1)
            {
                ret = get(r[0], r[1]);
            }
            else if(i>1) 
            {
                if(abs(COMPLEX(c_i.real()-ret.real(),c_i.imag()))>ret.imag())
                {
                    COMPLEX r1 = get(r[0], c_i);
                    COMPLEX r2 = get(r[1], c_i);
                    if(r1.imag()>r2.imag())
                    {
                        r2 = c_i;
                    }
                    else
                    {
                        r1 = c_i;
                    }
                    if(r1.imag()>ret.imag())
                    {
                        ret = r1;
                    }
                    else if(r2.imag()>ret.imag())
                    {
                        ret = r2;
                    }
                }
            }
            
        }
        if (homeNumber==1)
        {
            ret = COMPLEX(r[0].real(), abs(r[0].imag()));
            outputs.push_back(ret);
        }
        else if (homeNumber==2)
        {
            ret = get(r[0], r[1]);
            outputs.push_back(ret);
        }
        else
            outputs.push_back(ret);
        cin.getline (home_number,7); // Read the space
        cin.getline (home_number,7); // Read the next home number
        sscanf (home_number,"%d", &homeNumber);
    }
    for(int i = 0; i<outputs.size(); i++)
    {
        printf("%.9f %.9f\n", outputs[i].real(), outputs[i].imag());
    }
    return 0;
}
