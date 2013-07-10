/*
TASK: Electricity
Input:
5
9 9 1979 440
29 10 1979 458
30 10 1979 470
1 11 1979 480
2 11 1979 483
3
5 5 2000 6780
6 5 2001 7795
7 5 2002 8201
8
28 2 1978 112
1 3 1978 113
28 2 1980 220
1 3 1980 221
5 11 1980 500
14 11 2008 600
15 11 2008 790
16 12 2008 810
0
Output:
2 15
0 0
2 191
*/
/*if(nextday(1,7,1970,30,6,1970))
        cout<<"correct!"<<endl;
    else
        cout<<"wrong!"<<endl;
    if(nextday(2,7,1970,1,1,1970))
        cout<<"wrong!"<<endl;
    else
        cout<<"correct!"<<endl;
    if(nextday(1,3,2000,28,2,2000))
        cout<<"correct!"<<endl;
    else
        cout<<"wrong!"<<endl;
    if(nextday(1,3,2000,29,2,2000))
        cout<<"wrong!"<<endl;
    else
        cout<<"correct!"<<endl;
    if(nextday(1,2,1970,30,1,1970))
        cout<<"wrong!"<<endl;
    else
        cout<<"correct!"<<endl;
    if(nextday(1,3,1970,28,2,1970))
        cout<<"correct!"<<endl;
    else
        cout<<"wrong!"<<endl;
    if(nextday(1,3,1970,29,2,1970))
        cout<<"wrong!"<<endl;
    else
        cout<<"correct!"<<endl;*/
    
#include <iostream>
#include <vector>

using namespace std;

int day_month[] ={31,28,31,30,31,30,31,31,30,31,30,31};

bool nextday(int d1,int m1,int y1,int d2,int m2,int y2)
{
    if((m1==m2)&&(y1==y2))
    {
        if(d1==(d2+1))
            return true;
        else
            return false;
    }
    else if(y1==y2)
    {
        if((d1==1)&&(m1==(m2+1)))
        {
            if(m1!=3)
            {
                if(d2==day_month[m2-1])
                    return true;
                else
                    return false;
            }
            else 
            {
                if((y1%4==0)&&(y1%100!=0))
                {
                    if(d2==29)
                        return true;
                    else
                        return false;
                }
                else
                {
                    if(d2==28)
                        return true;
                    else
                        return false;
                }
            }
        }
        else
            return false;
    }
    else if((d2==31)&&(m2=12)&&(d1==1)&&(m1=1)&&(y1==(y2+1)))
        return true;
    else
        return false;
}


int main()
{
    int i, j, n, total, num;
    vector<vector<int> > dayss, monthss, yearss, mountss;
    scanf("%d", &n);
    while(n)
    {
        vector<int> days(n), months(n), years(n), mounts(n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d %d", &days[i], &months[i], &years[i], &mounts[i]);
        }
        dayss.push_back(days);
        monthss.push_back(months);
        yearss.push_back(years);
        mountss.push_back(mounts);   
        scanf("%d", &n);        
    }
    for(i=0;i<dayss.size();i++)
    {
        total=0;
        num=0;
        for(j=1;j<dayss[i].size();j++)
        {
            if(nextday(dayss[i][j],monthss[i][j],yearss[i][j],dayss[i][j-1],monthss[i][j-1],yearss[i][j-1]))
            {
                num++;
                total+=(mountss[i][j]-mountss[i][j-1]);
            }
        }
        printf("%d %d\n", num, total);
    }
    return 0;
}
