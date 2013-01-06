/*
 * 2012/11/29
 */
#include <iostream>
#include <math.h>
#include <vector>
#include <sstream>
using namespace std; 

#define TASK_NUM 10000
#define GRANULARITY 100

float getTriangleArea(float a, float b, float c)
{
    float p = (a+b+c)/2;
    //cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<", (a+b+c)/2 = "<<p<<endl;
    float S =  sqrt(p*(p-a)*(p-b)*(p-c));
    return S;
}

float getTriangleHigh(float a, float b, float c)
{
    float p = (a+b+c)/2;
    //cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<", (a+b+c)/2 = "<<p<<endl;
    float S =  sqrt(p*(p-a)*(p-b)*(p-c));
    float h = 2*S/a;
    //cout<<"p*(p-a)*(p-b)*(p-c) = "<<(p*(p-a)*(p-b)*(p-c))<<", S = "<<S<<", h = "<<h<<endl;
    return h;
};
//WX, WY, WZ, XY, XZ, YZ
float getTetrahedron(float WX, float WY, float WZ, float XY, float XZ, float YZ)
{
    float WE = getTriangleHigh(XY, WX, WY);
    float ZE = getTriangleHigh(XY, YZ, XZ);
    float WM = getTriangleHigh(ZE, WZ, WE);
    //cout<<"WE = "<<WE<<", ZE = "<<ZE<<", WM = "<<WM<<endl;
    //float WEZ = sinh(WM/WE);
    //float EM = WM/tan(WEZ);
    //float EM1 = WM*tan(WEZ);
    float EM = sqrt(WE*WE-WM*WM);
    float R = WM*EM/(EM+WE);
    //cout<<"tan(3.1415926/4) = "<<tan(3.1415926/4)<<endl;
    //cout<<"sin(WEZ) = "<<sin(WEZ)<<", WM/WZ = "<<WM/WZ<<endl;
    //cout<<"EM1 = "<<EM1<<", EM2 = "<<EM2<<endl;
    //cout<<"WEZ = "<<WEZ<<", EM = "<<EM<<", R = "<<R<<endl;
    return R;
};

int main() 
{
    /*char task_number[7];
    cin.getline (task_number,7); // Read the next number
    int taskNumber;
    sscanf (task_number,"%d", &taskNumber);  
    if ((taskNumber>0)&&(taskNumber<=TASK_NUM))
    {
        vector<string> input;
        for(int i= 0; i<taskNumber; ) 
        {
            
            char in[30];
            cin.getline (in, 30); // Read the next number
            int roomX, roomY, M;
            sscanf(in, "%d %d %d", &roomX, &roomY, &M);
            string str=in;
            input.push_back(str);
            while(M)
            {
                cin.getline (in, 30); // Read the next number
                str=in;
                input.push_back(str);
                M--;
            }
            i++;
        }
        
        Runaway(input);
    }*/
    /*cout<<sqrt(3.0)/2<<endl;
    cout<<getTriangleHigh(1,1,1)<<endl;
    cout<<getTriangleHigh(3,4,5)<<endl;
    cout<<getTriangleHigh(4,3,5)<<endl;
    cout<<getTriangleHigh(5,4,3)<<endl;*/
    
    //cout<<getTetrahedron(1,1,1,1,1,1)<<endl;
    //cout<<getTriangleHigh(1000,1000,1000)<<endl;
    //cout<<getTriangleHigh(5,1000,999)<<endl;
    //cout<<getTetrahedron(1000, 999, 998, 5, 5, 6)<<endl;
    cout<<"S(1000, 999, 5) = "<<getTriangleArea(1000, 999, 5)<<endl;
    cout<<"S(1000, 998, 5) = "<<getTriangleArea(1000, 998, 5)<<endl;
    cout<<"S(998, 999, 6) = "<<getTriangleArea(998, 999, 6)<<endl;
    cout<<getTetrahedron(998, 5, 5, 1000, 999, 6)<<endl;
    cout<<getTetrahedron(998, 5, 6, 1000, 999, 5)<<endl;
    cout<<getTetrahedron(998, 6, 5, 1000, 999, 5)<<endl;
    cout<<getTetrahedron(999, 5, 5, 1000, 998, 6)<<endl;
    cout<<getTetrahedron(999, 5, 6, 1000, 998, 5)<<endl;
    cout<<getTetrahedron(999, 6, 5, 1000, 998, 5)<<endl;
    cout<<getTetrahedron(1000, 5, 5, 999, 998, 6)<<endl;
    cout<<getTetrahedron(1000, 5, 5, 999, 6, 998)<<endl;
    cout<<getTetrahedron(1000, 5, 5, 998, 999, 6)<<endl;
    cout<<getTetrahedron(1000, 5, 5, 6, 999, 998)<<endl;
    cout<<getTetrahedron(1000, 5, 5, 998, 6, 999)<<endl;
    cout<<getTetrahedron(1000, 5, 5, 6, 998, 999)<<endl;
    return 0;
}
