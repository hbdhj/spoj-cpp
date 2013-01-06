/* Deng Haijun 2012/12/13
for i <- 2 to N
    j <- i
    while j > 1 and a[j] < a[j - 1]
       swap a[j] and a[j - 1]
       j <- j - 1
2
5
1 1 1 2 2
5
2 1 3 1 2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int tN, i, n, nn;
    cin>>tN;
    vector<vector<int> > nss;
    for(int i=0; i<tN; i++)
    {
        cin>>nn;
        vector<int> ns;
        for(int i=0;i<nn; i++)
        {
            cin>>n;
            ns.push_back(n);
        }
        nss.push_back(ns);
    }
    for(int m=0;m<nss.size();m++)
    {
        int swaptime=0;
        for (int i = 1; i<nss[m].size(); i++)
        {
            int j = i;
            while((j >= 1)&&(nss[m][j]<nss[m][j - 1]))
            {
                //swap nss[j] and nss[j - 1]
                int swap = nss[m][j];
                nss[m][j] = nss[m][j - 1];
                nss[m][j - 1] = swap;
                j = j - 1;
                swaptime++;
            }
        }
        /*for(int l=0; l<nss[m].size(); l++)
            cout<<nss[m][l]<<", ";*/
        cout<<swaptime<<endl;
        
    }
    return 0;
}
