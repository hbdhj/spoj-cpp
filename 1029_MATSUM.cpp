/*
1029. Matrix Summation

Input:
1
4
SET 0 0 1
SUM 0 0 3 3
SET 2 2 12
SUM 2 2 2 2
SUM 2 2 3 3
SUM 0 0 2 2
END

Output:
1
12
12
13
*/


#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct action
{
    string act;
    int start;  // point for set
    int end;    // num for set
};

int main()
{
    int i, j, n;
    vector<vector<action> > all_matrix_actions;
    scanf("%d",&n);
    vector<int> matrix_sizes(n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&matrix_sizes[i]);
        char act_c[3];
        scanf("%s", act_c);
        string act_s=act_c;
        vector<action> matrix_actions;
        
        while(act_s!="END")
        {
            action act;
            if(act_s=="SET")
            {
                //printf("Now try to get set_x, set_y, set_num\n");
                int set_x, set_y, set_num;
                scanf("%d", &set_x);
                scanf("%d", &set_y);
                scanf("%d", &set_num);
                act.act=act_c;
                act.start=set_x*matrix_sizes[i]+set_y;
                act.end=set_num;
            }
            else if(act_s=="SUM")
            {
                //printf("Now try to start_x, start_y, end_x, end_y\n");
                int start_x, start_y, end_x, end_y;
                scanf("%d", &start_x);
                scanf("%d", &start_y);
                scanf("%d", &end_x);
                scanf("%d", &end_y);
                act.act=act_c;
                act.start=start_x*matrix_sizes[i]+start_y;
                act.end=end_x*matrix_sizes[i]+end_y;
            }
            //printf("DEBUG1\n");
            //printf("DEBUG2\n");
            matrix_actions.push_back(act);
            //printf("DEBUG3\n");
            scanf("%s", act_c);
            //printf("DEBUG4\n");
            act_s=act_c;
            //printf("DEBUG5\n");            
        }
        all_matrix_actions.push_back(matrix_actions);
    }
    for(i=0;i<n;i++)
    {
        printf("The %d cases:\n",i+1);
        for(j=0;j<all_matrix_actions[i].size();j++)
        {
            printf("%s %d %d\n", all_matrix_actions[i][j].act.c_str(), all_matrix_actions[i][j].start, all_matrix_actions[i][j].end);
        }
        printf("\n");
    }
    return 0;
}