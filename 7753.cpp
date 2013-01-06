/*7753*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get(int n)
{
	int ret = 0;
	while(n>0)
	{
		ret += (n%10)*(n%10);
		n=n/10;
	}
	return ret;
}

int main()
{
    int tN,i,m;
    scanf("%d", &tN);
    vector<int> input;
    for(i=0;i<tN;i++)
    {
        scanf("%d", &m);
        input.push_back(m);
    }
    vector<int> repeats;
    for(i=0;i<tN;i++)
    {
        m = get(input[i]);
        int repeated = false;
        vector<int> results;
        while(m>1)
        {
            //cout<<m<<endl;
            if(find(repeats.begin(), repeats.end(), m)!=repeats.end())
            {
                repeated = true;
                break;
            }
            else if(find(results.begin(), results.end(), m)!=results.end())
            {
                repeated = true;
                repeats.push_back(m);
                break;
            }
            else
                results.push_back(m);
            m = get(m);
        }
        if(repeated)
            printf("-1\n");
        else
            printf("%d\n",results.size()+1);
    }
	return 0;
}