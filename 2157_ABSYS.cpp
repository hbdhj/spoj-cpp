/*
 TASK:  Anti-Blot System
 */
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	int tN;
	cin>>tN;
	vector<string> numbers;
	for(int i=0; i<tN; i++)
	{
		string input;
		cin>>input;
		numbers.push_back(input);
		cin>>input;
		cin>>input;
		numbers.push_back(input);
		cin>>input;
		cin>>input;
		numbers.push_back(input);
	}
	for(int i=0; i<tN; i++)
	{
		int a, b, c;
		stringstream ss;
		if(numbers[3*i].find("machula")!=string::npos)
		{
			sscanf(numbers[3*i+1].c_str(), "%d", &b);
			sscanf(numbers[3*i+2].c_str(), "%d", &c);
			a=c-b;
			ss<<a;
			cout<<ss.str()<<" + "<<numbers[3*i+1] << " = "<<numbers[3*i+2]<<endl;
		}
		else if(numbers[3*i+1].find("machula")!=string::npos)
		{
			sscanf(numbers[3*i].c_str(), "%d", &a);
			sscanf(numbers[3*i+2].c_str(), "%d", &c);
			b=c-a;
			ss<<b;
			cout<<numbers[3*i]<<" + "<< ss.str() << " = "<<numbers[3*i+2]<<endl;
		}
		else if(numbers[3*i+2].find("machula")!=string::npos)
		{
			sscanf(numbers[3*i].c_str(), "%d", &a);
			sscanf(numbers[3*i+1].c_str(), "%d", &b);
			c=b+a;
			ss<<c;
			cout<<numbers[3*i]<<" + "<<numbers[3*i+1]<< " = "<<ss.str()<<endl;
		}
	}
	return 0;
	
}
