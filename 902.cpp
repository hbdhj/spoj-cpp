#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int getCards(string hangover)
{
    float ho;
	//sscanf(hangover.c_str(), "%1.2f", &ho);
    sscanf(hangover.c_str(), "%f", &ho);
    //sscanf(hangover.c_str(), "%f", ho);
    //cout<<hangover<<","<<ho<<endl;
    float ret = 0.0;
    int n = 0;
    while(ret < ho )
    {
        n++;
        ret += 1.0/(n+1);
        //cout<<n<<", "<<ret<<endl;
    }
    return n;
}

int main()
{
	string hangover="";
	vector<string> inputs;
	while(hangover!="0.00")
	{
		cin>>hangover;
        if(hangover!="0.00")
            inputs.push_back(hangover);
	}
    for(int i =0; i<inputs.size(); i++)
	{
        cout<<getCards(inputs[i])<<" card(s)"<<endl;
	}
	
	return 0;
}
