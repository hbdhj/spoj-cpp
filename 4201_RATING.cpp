//
//  4201.cpp
//  CPPEditor
//
//  Created by Haijun Deng on 12-12-26.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int student_num, high_school_score, open_comp_score;
    cin>>student_num;
    vector<int> h_s_s_l, o_c_s_l;
    for(int i=0;i<student_num; i++)
    {
        cin>>high_school_score;
        h_s_s_l.push_back(high_school_score);
        cin>>open_comp_score;
        o_c_s_l.push_back(open_comp_score);
    }
    //sort(high_school_score.begin(),high_school_score.end());
    //sort(open_comp_score_list.begin(),open_comp_score_list.end());
    for(int i=0;i<student_num; i++)
    {        
        /*int high_school_ranking, open_comp_ranking;
        high_school_ranking = 0;
        open_comp_ranking = 0;*/
        int ranking = 0;
        for(int j=0;j<student_num;j++)
            if(j!=i)
            {
                /*if(high_school_score_list[i]>high_school_score_list[j])
                    high_school_ranking++;
                if(open_comp_score_list[i]>open_comp_score_list[j])
                    open_comp_ranking++;*/
                if((o_c_s_l[i]>o_c_s_l[j])&&(h_s_s_l[i]>=h_s_s_l[j]))
                    ranking++;
                else if((o_c_s_l[i]>=o_c_s_l[j])&&(h_s_s_l[i]>h_s_s_l[j]))
                    ranking++;
            }
        cout<<ranking<<endl;
        //cout<<(high_school_ranking<open_comp_ranking?high_school_ranking:open_comp_ranking)<<endl;
        //high_school_ranking = find(high_school_score.begin(),high_school_score.end(), )
        //high_school_ranking = find(high_school_score.begin(),high_school_score.end(), )
    }
    return 0;
}
