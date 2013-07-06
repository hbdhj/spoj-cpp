/*Deng Haijun 2012/12/17 
TASK: Candy I

Input file:
5
1
1
1
1
6
2
3
4
-1

Output file:
4
-1*/

#include <iostream>
#include <vector>
//#include <fstream>

using namespace std;

int main(int argc, char **argv)
{    
    vector<vector<int> > candyslist;
    
	int packetNumber;
    scanf("%d", &packetNumber);
    //cin>> packetNumber; // sets EOF flag if no value found
    while(packetNumber!=-1)
    {        
        vector<int> candys;
        for(int i=0;i<packetNumber;i++)
        {
            int candy;
            //cin >> candy;
            scanf("%d", &candy);
            candys.push_back(candy);
        }
        candyslist.push_back(candys);
        scanf("%d", &packetNumber);
        //cin>>packetNumber;
    }
    for(int i=0;i<candyslist.size();i++)
    {
        int total = 0;
        for(int j=0;j<candyslist[i].size();j++)
            total+=candyslist[i][j];
        if(total%candyslist[i].size()!=0)
            cout<<-1<<endl;
        else
        {
            int means = total/candyslist[i].size();
            int moves = 0;
            for(int j=0;j<candyslist[i].size();j++)
            {
                if(candyslist[i][j]>means)
                    moves+=candyslist[i][j]-means;
            }
            cout<<moves<<endl;
        }
    }
   
	return 0;
}
