/*
Deng Haijun
2012 12/19
95. Street Parade
Sample input:
5
1 2 3 4 5
5
5 1 2 4 3 
5
5 1 2 3 4 
5
5 3 2 1 4
10
1 2 10 5 4 3 7 6 8 9
0
Sample output:
yes
no
*/
#include <vector>
#include <iostream>
using namespace std;

int getParades(vector<int> Parade)
{
    vector<int> revert;
    int expected = 1;
    for(int i=0; i<Parade.size();i++)
    {
        if(Parade[i]==expected)
            expected++;
        else
        {
            if(revert.size()>0)
            {
                if(revert[revert.size()-1]==expected)
                while(revert.size()>0)
                {
                    if(revert[revert.size()-1]==expected)
                    {
                        revert.pop_back();
                        expected++;
                    }
                    else 
                        break;
                }
            }
            revert.push_back(Parade[i]);            
        }    
    }
    if(revert.size()==0)
        cout<<"yes"<<endl;
    else
    {
        bool get_expected = true;        
        for(int i=revert.size()-1; i>=0;i--)
        {
            if(revert[i]!=expected)
            {
                get_expected = false;
                break;
            }
            else
                expected++;
        }
        if (get_expected)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;    
    }       
    return 0;
}
int main()
{
    int num;
    cin>>num;
    vector<vector<int> > Parades;
    while(num!=0)
    {
        vector<int> Parade;
        for(int i=0;i<num;i++)
        {
            int n;
            cin>>n;
            Parade.push_back(n);
        }
        Parades.push_back(Parade);
        cin>>num;
    }
    for(int i=0;i<Parades.size();i++)
    {
        getParades(Parades[i]);
    }
    return 0;
}