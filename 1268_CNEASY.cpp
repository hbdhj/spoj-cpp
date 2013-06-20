/*
 * 2012/11/28
 TASK: CN Tower (Easy)
 */
#include  <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std; 

//#define TASK_NUM 100
#define EXPR_LENGTH 100
#define CASE_LENGTH 5
#define SPEED    4320

float maxSpace(vector<float> vec)
{
    float max = 0.0;
    int compare = vec.size() - 1;
    for(int i = 0; i<compare; i++)
    {
        if(max<(vec[i+1]-vec[i]))
            max = vec[i+1]-vec[i];
    }
    if(max < (vec[0]-vec[compare]+360))
        max = vec[0]-vec[compare]+360;
    return max;
}
int main() 
{
    char case_number[CASE_LENGTH];
    cin.getline (case_number,CASE_LENGTH); // Read the next number
    int caseNumber;
    sscanf (case_number,"%d", &caseNumber);
    vector<float> output;
    while (caseNumber>0)
    {
        //cout<<"caseNumber ="<<caseNumber<<endl;
        char landmark_number[CASE_LENGTH];
        cin.getline (landmark_number, CASE_LENGTH); // Read the next number
        int landmarknumber;
        sscanf (landmark_number,"%d", &landmarknumber);
        if ((landmarknumber>=2)&&(landmarknumber<=1000))
        {
            //cout<<"landmarknumber ="<<landmarknumber<<endl;
            vector<float> vec;
            vector<float>::iterator finded;
            while(landmarknumber) 
            {
                char strinput[EXPR_LENGTH];
                cin.getline(strinput, EXPR_LENGTH); // Read the next number
                char landmark_name[EXPR_LENGTH];
                float landmark_direction;
                sscanf (strinput,"%s %f", landmark_name, &landmark_direction);
                //cout<<"landmark_name ="<<landmark_name<<endl;        
                //cout<<"landmark_direction ="<<landmark_direction<<endl; 
                finded = find(vec.begin(), vec.end(), landmark_direction);
                if(finded==vec.end())
                    vec.push_back(landmark_direction);
                landmarknumber--;
            }
            sort (vec.begin(), vec.end());
            float max = 0.0;
            int compare = vec.size() - 1;
            for(int i = 0; i<compare; i++)
            {
                if(max<(vec[i+1]-vec[i]))
                max = vec[i+1]-vec[i];
            }
            if(max < (vec[0]-vec[compare]+360))
                max = vec[0]-vec[compare]+360;
            output.push_back(max/360*4320);            
        }
        caseNumber--;
    }
    for(int i = 0; i<output.size(); i++)
        cout<<(4320-int(output[i]))<<endl;
    return 0;
}
