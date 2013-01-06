/*
10395. Sum of divisors!
Input:
2
1 5
9 10
Output:
2
1
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int getHNum(int start, int end)
{
    int num=0;
    int s_start = sqrt(float(start));
    int s_end = sqrt(float(end));
    //printf("s_start = %d, s_end = %d\n",s_start,s_end);
    if(start==end)
    {
        if(s_end*s_end==end)
            num++;
        if(1==end)
            num--;    
        if(2==end)
            num++;    
    }
    else
    {
        num=s_end-s_start;
        //if((s_end*s_end==end)&&(s_start*s_start==start))
        if(s_start*s_start==start)
            num++;
        if((2<=end)&&(2>=start))
            num++;
        //if(1==end)
        //    num--;
        if(1==start)
            num--;
    }
    return num;
}
int main()
{
    int tN, start, end, i, num;
    scanf("%d", &tN);
    vector<int> inputs;
    for(i=0;i<tN;i++)
    {
        scanf("%d %d",&start,&end);
        inputs.push_back(start);
        inputs.push_back(end);
    }
    for(i=0;i<tN;i++)
    {
        start=inputs[i*2];
        end=inputs[i*2+1];

        printf("%d\n",getHNum(start, end));    
    }
    /*printf("HNumber(%d, %d) = %d\n",1,1,getHNum(1,1));   
    printf("HNumber(%d, %d) = %d\n",1,2,getHNum(1,2));   
    printf("HNumber(%d, %d) = %d\n",2,2,getHNum(2,2));   
    printf("HNumber(%d, %d) = %d\n",1,3,getHNum(1,3));   
    printf("HNumber(%d, %d) = %d\n",2,3,getHNum(2,3));   
    printf("HNumber(%d, %d) = %d\n",3,3,getHNum(3,3));   
    printf("HNumber(%d, %d) = %d\n",1,4,getHNum(1,4));   
    printf("HNumber(%d, %d) = %d\n",2,4,getHNum(2,4));   
    printf("HNumber(%d, %d) = %d\n",3,4,getHNum(3,4));   
    printf("HNumber(%d, %d) = %d\n",4,4,getHNum(4,4));   
    printf("HNumber(%d, %d) = %d\n",1,5,getHNum(1,5));   
    printf("HNumber(%d, %d) = %d\n",2,5,getHNum(2,5));   
    printf("HNumber(%d, %d) = %d\n",3,5,getHNum(3,5));   
    printf("HNumber(%d, %d) = %d\n",4,5,getHNum(4,5));   
    printf("HNumber(%d, %d) = %d\n",5,5,getHNum(5,5));   
    printf("HNumber(%d, %d) = %d\n",1,6,getHNum(1,6));   
    printf("HNumber(%d, %d) = %d\n",2,6,getHNum(2,6));   
    printf("HNumber(%d, %d) = %d\n",3,6,getHNum(3,6));   
    printf("HNumber(%d, %d) = %d\n",4,6,getHNum(4,6));   
    printf("HNumber(%d, %d) = %d\n",5,6,getHNum(5,6));   
    printf("HNumber(%d, %d) = %d\n",6,6,getHNum(6,6));*/  
    return 0;
}