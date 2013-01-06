/* Deng Haijun 2012/12/18
94. Numeral System of the Maya
Sample input:
1
..

5
... -
. - -
S
S
S

0
Sample output:
2
1231200
*/
#include <iostream>
#include <vector>
using namespace std;
#define LINE_LENGTH 10

int getMayaBit(string& num)
{
    if(num=="S")
        return 0;
    else
    {
        int ret = 0;
        for(int i=0; i<num.size(); i++)
        {
            if(num[i]=='.')
                ret+=1;
            else if(num[i]=='-')
                ret+=5;
        }
        return ret;
    }    
}

int getMayaNum(vector<string>& nums)
{
    int ret = 0;
    int base =  1;
    for(int i=nums.size()-1;i>=0;i--)
    {
        //cout<<getMayaBit(nums[i])<<endl;
        ret += base*getMayaBit(nums[i]);
        //cout<<"base = "<<base<<", Bit = "<<getMayaBit(nums[i])<<", ret = "<<ret<<endl;
        if(i==(nums.size()-2))
            base = base*18;
        else
            base = base*20;
    }
    return ret;
}

int main()
{
    char t_N[5];
    //cin.getline(t_N, 5);
    int tN;
    //sscanf(t_N, "%d", &tN);
    scanf("%d", &tN);
    vector<vector<string> > mayaNumStrList;
    while(tN!=0)
    {
        vector<string> mayaNumStr;
        cout<<"tN = "<<tN<<endl;
        for(int i=0; i<tN; i++)
        {
            char input1[LINE_LENGTH];
            char input2[LINE_LENGTH];
            scanf("%s %s", input1, input2);
            //cin.getline(input, LINE_LENGTH);
            string str = input1;
            str+=input2;
            cout<<"str = "<<str<<endl;
            mayaNumStr.push_back(str);
        }
        mayaNumStrList.push_back(mayaNumStr);
        //cin.getline(t_N, 5);
        scanf("%d", &tN);
        scanf("%d", &tN);
        //cin.getline(t_N, 5);
        //sscanf(t_N, "%d", &tN);
        //cout<<"tN = "<<tN<<endl;
    }
    for(int i=0;i<mayaNumStrList.size();i++)
        //for(int j=0;j<mayaNumStrList[i].size();j++)
            cout<<getMayaNum(mayaNumStrList[i])<<endl;
    //vector<vector<int> > mayaNumList;
    
    return 0;
}