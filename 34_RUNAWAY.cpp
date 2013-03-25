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
//#define ACCURACY 0.01
#define ZOOM 10

class point
{
public:
    unsigned long X;
    unsigned long Y;
    /*point()
    {
       X = 0.0;
       Y = 0.0;
    }
    point(float x, float y)
    {
       X = x;
       Y = y;
    }
    point(point &p)
    {
       X = p.X;
       Y = p.Y;
    }*/
};

class room
{
public:
    point leftdown;
    point rightup;
    /*room()
    {
       leftdown = point(0.0, 0.0);
       rightup = point(0.0, 0.0);
    }
    room(room &r)
    {
       leftdown = r.leftdown;
       rightup = r.rightup;
    }*/
};

float dis(point p1, point p2)
{
    //return sqrt(float((p1.X-p2.X)*(p1.X-p2.X)+(p1.Y-p2.Y)*(p1.Y-p2.Y)));
    return (p1.X-p2.X)*(p1.X-p2.X)+(p1.Y-p2.Y)*(p1.Y-p2.Y);
}

unsigned long gran = 100000;
point maxpoint;

int checkRoom(room r, vector<point> holes)
{
    //cout<<"Now granularity = "<<gran<<endl;
    //cout<<"(r.leftdown).X = "<<(r.leftdown).X<<", (r.leftdown).Y = "<<(r.leftdown).Y<<endl;
    //cout<<"(r.rightup).X = "<<(r.rightup).X<<", (r.rightup).Y = "<<(r.rightup).Y<<endl;
    if (gran>1)
    {
        float shortb;
        if((r.rightup.X - r.leftdown.X)>(r.rightup.Y - r.leftdown.Y))
        {
            shortb = (r.rightup.Y - r.leftdown.Y);
        }
        else
        {
            shortb = (r.rightup.X - r.leftdown.X);
        }
        gran = shortb/GRANULARITY;
        if (gran==0)
            gran = 1;
        //cout<<"Now shortb = "<<shortb<<", granularity = "<<gran<<endl;
        unsigned long maxdis = 0;
        for(unsigned long i = r.leftdown.X; i<=r.rightup.X; )
        {
            for(unsigned long j = r.leftdown.Y; j<=r.rightup.Y; )
            {
                point tocheck;
                tocheck.X = i;
                tocheck.Y = j;
                //cout<<"Checking ("<<i<<", "<<j<<")"<< endl;
                /*float mindis = ((r.rightup).X - (r.leftdown).X)*((r.rightup).X - (r.leftdown).X)
                              +((r.rightup).Y - (r.leftdown).Y)*((r.rightup).Y - (r.leftdown).Y);*/
                unsigned long mindis = 1000000000;
                for(unsigned long k = 0;k<holes.size();k++)
                {
                    float distance = dis(tocheck, holes[k]);
                    if(mindis>distance)
                    {
                        mindis = distance;
                    }
                }
                if(mindis>maxdis)
                {
                    maxdis = mindis;
                    //cout<<"i = "<<i<<", j = "<<j<<endl;
                    maxpoint.X = i;
                    maxpoint.Y = j;                
                }
                j+=gran; 
                //j+=1;
            }
            i+=gran;
            //i+=1;
        }
        //cout<<"maxpoint.X = "<<maxpoint.X<<endl;
        //cout<<"maxpoint.Y = "<<maxpoint.Y<<endl;
        room nr;
        (nr.leftdown).X = (maxpoint.X - gran)<((r.leftdown).X)?((r.leftdown).X):(maxpoint.X - gran);
        (nr.leftdown).Y = (maxpoint.Y - gran)<((r.leftdown).Y)?((r.leftdown).Y):(maxpoint.Y - gran);
        (nr.rightup).X = (maxpoint.X + gran)>((r.rightup).X)?((r.rightup).X):(maxpoint.X + gran);
        (nr.rightup).Y = (maxpoint.Y + gran)>((r.rightup).Y)?((r.rightup).Y):(maxpoint.Y + gran);
        //cout<<"(nr.leftdown).X = "<<(nr.leftdown).X<<", (nr.leftdown).Y = "<<(nr.leftdown).Y<<endl;
        //cout<<"(nr.rightup).X = "<<(nr.rightup).X<<", (nr.rightup).Y = "<<(nr.rightup).Y<<endl;
        //cout<<"################################################################"<<endl;
        checkRoom(nr, holes);    
    }
    
    return 0;
}

int Runaway(vector<string> inputs)
{
    int i = 0;
    int roomX, roomY, Ui, Vi, holeId, holeNumToget, M = 0;
    vector<point> holes;
    point hole;
    room r;
    while (i<inputs.size())
    {
        //int roomX, roomY, Ui, Vi, holeId, holeNumToget, M = 0;
        if(M)
        {
            sscanf(inputs[i].c_str(), "%d %d", &Ui, &Vi);
            holeNumToget --;
            //cout<<"U"<<holeId<<" = "<<Ui<<", V"<<holeId<<" = "<<Vi<<endl;
            hole.X = Ui*ZOOM;
            hole.Y = Vi*ZOOM;            
            holes.push_back(hole);
            holeId++;
        }    
        else
        {
            sscanf(inputs[i].c_str(), "%d %d %d", &roomX, &roomY, &M);
            holeNumToget = M;
            //cout<<"roomX = "<<roomX<<", roomY = "<<roomY<<", M = "<<M<<endl;
            gran = 1000000;
            (r.rightup).X = roomX*ZOOM;
            (r.rightup).Y = roomY*ZOOM;
            (r.leftdown).X = (r.leftdown).Y = 0;
            holes.clear();
            holeId = 0;
        }
        i++;
        //cout<<"holeNumToget = "<<holeNumToget<<endl;
            
        if(holeNumToget)
        {
            /*Use to get more hole*/
            continue;
        }
        else
        {
            /*Use to find the runaway*/
            checkRoom(r, holes);
            printf("The safest point is (%.1f, %.1f).\n", float(maxpoint.X)/ZOOM, float(maxpoint.Y)/ZOOM);
            /*Reset M to continue get next room*/
            M = 0;
        }        
    }    
}

int main() 
{
    char task_number[7];
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
    }      
    return 0;
}
