/*Deng Haijun 2012/12/11 400. To and Fro*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int col;
    cin>>col;
    //cout<<col<<endl;
    vector<int> cols;
    vector<string> strs;
    while(col>0)
    {
        cols.push_back(col);
        string str;
        cin>>str;
        //cout<<str<<endl;
        strs.push_back(str);
        cin>>col;
        //cout<<col<<endl;
    }
    for(int i=0;i<strs.size();i++)
    {
        //cout<<"strs[i] = "<<strs[i]<<endl;;
        //cout<<"strs[i].length() = "<<strs[i].length();
        //cout<<"col ="<<cols[i]<<endl;
        int row = strs[i].length()/cols[i];
        //cout<<"row = "<<row<<endl;
        for(int j=0;j<cols[i]; j++)
        {   
            for(int k=0;k<row/2; k++)
            {
                //cout<<"Print c["<< j+k*2*cols[i]<< "] and c["<< (k+1)*2*cols[i]-j-1<<"]"<<endl;
                cout<<strs[i][j+k*2*cols[i]]<<strs[i][(k+1)*2*cols[i]-j-1];
            }        
            if(row%2)
            {
                //cout<<endl<<"Print c["<< (row-1)*cols[i]+j<< "]"<<endl;
                cout<<strs[i][(row-1)*cols[i]+j];
            }    
        }    
        cout<<endl;
    }
    return 0;
}
