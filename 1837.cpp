/*
1837. Pie
Input:
3
3 3
4 3 3
1 24
5
10 5
1 4 2 3 4 5 6 5 4 2
Output:
25.1327
3.1416
50.2655
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float getBiggestPie(vector<int> sortedPieSizes, int peopleNum)
{
    cout<<"Now "<<peopleNum<<" peoples eat "<<sortedPieSizes.size()<<" pies: ";
    //cout<<"haha"<<endl;
    int i;
    for(i=0; i<sortedPieSizes.size()-1;i++)
        cout<<sortedPieSizes[i]<<", ";
    cout<<sortedPieSizes[i]<<"."<<endl;
    float ret;
    if(sortedPieSizes.size()==1)
        ret = M_PI*sortedPieSizes[0]*sortedPieSizes[0]/peopleNum;
    else
    {
        if(peopleNum==1)
            return M_PI*sortedPieSizes[sortedPieSizes.size()-1]*sortedPieSizes[sortedPieSizes.size()-1];
        else if(peopleNum==2)
        {
            if((sortedPieSizes[sortedPieSizes.size()-1]*sortedPieSizes[sortedPieSizes.size()-1])
              >(sortedPieSizes[sortedPieSizes.size()-2]*sortedPieSizes[sortedPieSizes.size()-2]))
                ret =  M_PI*sortedPieSizes[sortedPieSizes.size()-1]*sortedPieSizes[sortedPieSizes.size()-1]/2;
            else
                ret =  M_PI*sortedPieSizes[sortedPieSizes.size()-2]*sortedPieSizes[sortedPieSizes.size()-2];
        }   
        else
        {
            vector<int> sortedPieSizes_withoutFirst(sortedPieSizes.begin()+1, sortedPieSizes.end());
            float spoilFirst = getBiggestPie(sortedPieSizes_withoutFirst, peopleNum);
            if (M_PI*sortedPieSizes[0]*sortedPieSizes[0]<spoilFirst)
                ret =  spoilFirst;
            else
            {
                int peopleOnFirstPie = 1;
                spoilFirst = getBiggestPie(sortedPieSizes_withoutFirst, peopleNum-peopleOnFirstPie);
                while(M_PI*sortedPieSizes[0]*sortedPieSizes[0]/peopleOnFirstPie>spoilFirst)
                {
                    peopleOnFirstPie++;
                    spoilFirst = getBiggestPie(sortedPieSizes_withoutFirst, peopleNum-peopleOnFirstPie);                
                }
                ret =  spoilFirst;
            }
        }  
    }
    printf("the max is %.4lf\n", ret);
    return ret;
}
int main()
{
    int tN,i,j,n,peopleNum,pieNum, pieSize;
    vector<int> peopleNumList;
    vector<vector<int> > pieSizesList;
    cin>>tN;
    for(i=0;i<tN;i++)
    {
        cin>>pieNum;
        cin>>peopleNum;
        //cout<<pieNum<<", "<<peopleNum<<endl;
        vector<int> pieSizes;
        for(j=0;j<pieNum;j++)
        {
            cin>>pieSize;
            pieSizes.push_back(pieSize);
        }
        pieSizesList.push_back(pieSizes);
        peopleNumList.push_back(peopleNum);
    }
    //cout<<"Starting ..."<<endl;
    for(i=0;i<tN;i++)
    {
        sort(pieSizesList[i].begin(), pieSizesList[i].end());
        //cout<<"Sorting "<<pieSizesList[i].size()<<endl;
        for(j=0;j<pieSizesList[i].size();j++)
            cout<<pieSizesList[i][j]<<", ";
        cout<<endl;    
        cout<<peopleNumList[i]<<endl;
        float ret = getBiggestPie(pieSizesList[i], peopleNumList[i]);
        printf("%.4lf\n", ret);
        //cout<<getBiggestPie(pieSizesList[i], peopleNumList[i])<<endl;
    }
    return 0;
}
