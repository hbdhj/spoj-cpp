#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define EXPR_LENGTH 50

int getContinuousFractions(int n1, int n2)
{
    int remain = n1%n2;
    int div = n1 / n2;
    cout<<"div ="<<div<<", remain = "<<remain<<endl;
        
    if(remain)
    {
        getContinuousFractions(n2, remain);
    }
    return 0;
}

int getContinuousFractions(string input)
{
    int n1, n2;
	//sscanf(hangover.c_str(), "%1.2f", &ho);
    sscanf(input.c_str(), "%d %d", &n1, &n2);
    //sscanf(hangover.c_str(), "%f", ho);
    getContinuousFractions(n1, n2);
    return 0;
}

int main()
{
	char strinput[EXPR_LENGTH];
    string str="";
	vector<string> inputs;
	while(str!="0 0")
	{
		cin.getline (strinput,EXPR_LENGTH);
        str = strinput;
        if(str!="0 0")
            inputs.push_back(str);
	}
    for(int i =0; i<inputs.size(); i++)
	{
        cout<<"Case "<<i+1<<":"<<endl;
        getContinuousFractions(inputs[i]);
	}
	
	return 0;
}