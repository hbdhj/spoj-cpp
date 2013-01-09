/*
5
00:00
03:00
00:00
00:10
06:00
12:00
11:59
12:01
00:00
12:00
Output
2
0
6
1
11
*/
#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    float matchTime[22];
    for(int hour=1;hour<23;hour++)
    {
        if(hour>11)
            matchTime[hour-2]=60.0/11*(hour-12)+hour*60;
        else
            matchTime[hour-1]=60.0/11*hour+hour*60;
    }
    for(int hour=0;hour<21;hour++)
    {
        //System.out.print(hour+1 + "th meet time is " + matchMinus[hour]+" = ");
        //System.out.println((int)(matchMinus[hour]/60)+":"+(int)(matchMinus[hour]%60));
        printf("%dth meet time is %.2f = %02d:%02d\n", hour+1, matchTime[hour], (int)(matchTime[hour]/60), (int)(matchTime[hour]%60));
    }
			
    int num, hour, minute;
    scanf("%d", &num);
    //String[] strinputs=new String[num*2];
    vector<int> inputs;
    // read the inputs
    for(int i=0;i<num*2;)
    {
        scanf("%d:%d", &hour, &minute);
	    inputs.push_back(hour*60+minute);
    }
    //Check the times
    for(int i=0;i<num;i++)
    {
        //System.out.println(inputs[i]);
        if(inputs[i*2]<inputs[i*2+1])
        {
            int start=0;
            int end=0;
            for(int j=0;j<21;j++)
            {
                //System.out.format("matchTime[%d] = %.2f, inputs[%d] = %d, inputs[%d] = %d%n", j, matchTime[j], i*2, inputs[i*2], i*2+1, inputs[i*2+1]);
                if(matchTime[j]<inputs[i*2])
                    start=j+1;
                if(matchTime[j]<=inputs[i*2+1])
                    end=j+1;
                else
                    break;
            }
            //if(matchTime[21]<=inputs[i*2+1])
            //	end=22;
            //System.out.format("start = %d, end= %d%n", start, end);
            printf("%d\n", end-start);
        }
        else
            printf("0\n");
    }
	return 0;
}