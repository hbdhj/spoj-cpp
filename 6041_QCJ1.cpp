/*
6041. Mountain Walking
Input:
3

  /\
 /  \
/    \

Output:
Total Walk Distance = 6
Up 3 steps
Down 3 steps

Input:
2

 _____  ___
/     \/   \


Output:
Total Walk Distance = 12
Up 1 steps
Walk 5 steps
Down 1 steps
Up 1 steps
Walk 3 steps
Down 1 steps

Input:
5

        _
   /\__/ \
  /       \
 /         \/\_
/              \

Output:
Total Walk Distance = 16
Up 4 steps
Down 1 steps
Walk 2 steps
Up 1 steps
Walk 1 steps
Down 3 steps
Up 1 steps
Down 1 steps
Walk 1 steps
Down 1 steps

*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Get the input
    char t_N[5];
    cin.getline(t_N, 5);
    int n;
    sscanf(t_N, "%d", &n);
    vector<string> mountains;
    for(int i=0;i<n;)
    {
        char line[200];
        cin.getline(line, 200);
        string mountain=line;
        if(mountain.length()>0)
        {
            mountains.push_back(mountain);
            i++;
        }
    }
    // process the inputs
    int level=n-1;
    int length=mountains[level].length();
    string route(length, ' ');
    cout<<"Total Walk Distance = "<<length<<endl;
    int formerstate=0;
    int currentstate=0;//1: up, 2: walk, 3: down
    int distance=0;
    for(int i=0;i<length;i++)
    {
        distance++;
        route[i]=mountains[level][i];
        // Change the state
        if(route[i]==47)
        {
            currentstate=1;
        }
        else if(route[i]==92)
        {
            currentstate=3;
        }
        else if(route[i]=='_')
        {
            currentstate=2;
        }
        // decide the next
        if((mountains[level][i+1]==' ')||(mountains[level][i+1]==0))
        {
            if(level>0)
            {
                if((mountains[level-1][i+1]=='_')||(mountains[level-1][i+1]==47)||(mountains[level-1][i+1]==92))
                    level--;
            }        
            if(level<n-1)
            {
                if((mountains[level+1][i+1]=='_')||(mountains[level+1][i+1]==47)||(mountains[level+1][i+1]==92))
                    level++;
            }        
        }
        // print when state change
        if(formerstate!=currentstate)
        {
            if(formerstate==1)
                printf("Up %d steps\n", distance);
            if(formerstate==2)
                printf("Walk %d steps\n", distance);
            if(formerstate==3)
                printf("Down %d steps\n", distance);
            formerstate=currentstate;    
            distance=0;
        }
    }
    //print the last
    if(formerstate==0)
        printf("Walk %d steps\n", distance);
    if(formerstate==1)
        printf("Up %d steps\n", ++distance);
    if(formerstate==2)
        printf("Walk %d steps\n", ++distance);
    if(formerstate==3)
        printf("Down %d steps\n", ++distance);
    return 0;
}