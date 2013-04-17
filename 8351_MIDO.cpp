//
//  8351_MIDO.cpp
//  
//
//  Created by Haijun Deng on 13-4-16.
//  Copyright (c) 2013年 __MyCompanyName__. All rights reserved.
//
/*
 input 
 3 
 1 01:10 
 2 21:10 
 2 31:30 
 
 output 
 20:00 
 16:30 
 
 3 
 1 01:40 
 2 02:20 
 1 03:10 
 
 output 
 20:00 
 16:30 
 */
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int main()
{
    int scores, minute, second, team;
    scanf("%d", &scores);
    int i;
    /*vector<int> teams(scores,0), minutes(scores,0), seconds(scores,0);
    for (i=0; i<scores; i++) 
    {
        scanf("%d %d:%d",&teams[i], &minutes[i], &seconds[i]);
    }
    int team1_score=0;
    int team2_score=0;
    int team1_head_minutes=0;
    int team2_head_minutes=0;
    int team1_head_seconds=0;
    int team2_head_seconds=0;
    
    for (i=0; i<scores; i++) 
    {
        //printf("%d %d %d\n",teams[i], minutes[i], seconds[i]);
        if(teams[i]==1)
            team1_score++;
        if(teams[i]==2)
            team2_score++;
        if(team1_score>(team2_score+1)) 
        {
            if(seconds[i]>=seconds[i-1])
            {
                team1_head_minutes+=(minutes[i]-minutes[i-1]);
                team1_head_seconds+=(seconds[i]-seconds[i-1]);
            }
            else
            {
                team1_head_minutes+=(minutes[i]-minutes[i-1]-1);
                team1_head_seconds+=(seconds[i]+60-seconds[i-1]);
            }
        }
        //printf("%d %02d:%02d %d %02d:%02d\n",team1_score, team1_head_minutes,team1_head_seconds,team2_score, team2_head_minutes,team2_head_seconds);
        
        if(team2_score>(team1_score+1)) 
        {
            if(seconds[i]>=seconds[i-1])
            {
                team2_head_minutes+=(minutes[i]-minutes[i-1]);
                team2_head_seconds+=(seconds[i]-seconds[i-1]);
            }
            else
            {
                team2_head_minutes+=(minutes[i]-minutes[i-1]-1);
                team2_head_seconds+=(seconds[i]+60-seconds[i-1]);
            }
        }
        //printf("%d %02d:%02d %d %02d:%02d\n",team1_score, team1_head_minutes,team1_head_seconds,team2_score, team2_head_minutes,team2_head_seconds);
        
        if(team2_score==team1_score) 
        {
            if(teams[i]==1)
            {
                if(seconds[i]>=seconds[i-1])
                {
                    team2_head_minutes+=(minutes[i]-minutes[i-1]);
                    team2_head_seconds+=(seconds[i]-seconds[i-1]);
                }
                else
                {
                    team2_head_minutes+=(minutes[i]-minutes[i-1]-1);
                    team2_head_seconds+=(seconds[i]+60-seconds[i-1]);
                }
            }
            else
            {
                if(seconds[i]>=seconds[i-1])
                {
                    team1_head_minutes+=(minutes[i]-minutes[i-1]);
                    team1_head_seconds+=(seconds[i]-seconds[i-1]);
                }
                else
                {
                    team1_head_minutes+=(minutes[i]-minutes[i-1]-1);
                    team1_head_seconds+=(seconds[i]+60-seconds[i-1]);
                }
            }
        }
        //printf("%d %02d:%02d %d %02d:%02d\n",team1_score, team1_head_minutes,team1_head_seconds,team2_score, team2_head_minutes,team2_head_seconds);
        
    }
    if(team2_score>team1_score)
    {
        team2_head_minutes+=(47-minutes[i-1]);
        team2_head_seconds+=(60-seconds[i-1]);
    }
    if(team2_score<team1_score)
    {
        team1_head_minutes+=(47-minutes[i-1]);
        team1_head_seconds+=(60-seconds[i-1]);
    }
    //printf("%d %02d:%02d %d %02d:%02d\n",team1_score, team1_head_minutes,team1_head_seconds,team2_score, team2_head_minutes,team2_head_seconds);
    if(team1_head_seconds>=60)
        team1_head_minutes+=team1_head_seconds/60;
    team1_head_seconds=team1_head_seconds%60;
    if(team2_head_seconds>=60)
        team2_head_minutes+=team2_head_seconds/60;
    team2_head_seconds=team2_head_seconds%60;
    printf("%02d:%02d\n%02d:%02d\n",team1_head_minutes,team1_head_seconds,team2_head_minutes,team2_head_seconds);*/
    vector<int> teams(48*60,0);
    for (i=0; i<scores; i++) 
    {
        scanf("%d %d:%d",&team, &minute, &second);
        teams[minute*60+second] = team;
    }
    int team1_score=0;
    int team2_score=0;
    int team1_seconds=0;
    int team2_seconds=0;
    int former=0;
    for (i=0; i<48*60; i++) 
    {
        if(teams[i]==1)
            team1_score++;
        else if(teams[i]==2)
            team2_score++;
        else
            continue;
        if(team1_score>(team2_score+1)) 
        {
            team1_seconds+=i-former;
        }
        printf("%d %d %d %d %d\n",team1_score, team1_seconds, team2_score, team2_seconds, former);
        
        if(team2_score>(team1_score+1)) 
        {
            team2_seconds+=i-former;
        }
        printf("%d %d %d %d %d\n",team1_score, team1_seconds, team2_score, team2_seconds, former);
        
        if(team2_score==team1_score) 
        {
            if(teams[i]==1)
            {
                team2_seconds+=i-former;
            }
            else
            {
                team1_seconds+=i-former;
            }
        }
        printf("%d %d %d %d %d\n",team1_score, team1_seconds, team2_score, team2_seconds, former);
        
        former=i;
    }
    if(team2_score>team1_score)
    {
        team2_seconds+=(48*60-former);
    }
    if(team2_score<team1_score)
    {
        team1_seconds+=(48*60-former);
    }
    printf("%02d:%02d\n%02d:%02d\n",team2_seconds/60,team2_seconds%60,team2_seconds/60,team2_seconds%60);
    
    return 0;
}