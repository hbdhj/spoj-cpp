/*
TASK: Triple Fat Ladies
*/
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string get(unsigned long i)
{
	string ret = "";
	if(i>3)
	{
		int left = i%4;
		stringstream ss;
		ss<<(i/4);
		ret =ss.str();
	}
	switch(i%4)
	{
		case 1:
			ret = ret + "192";
			break;
		case 2:
			ret =  ret + "442";
			break;
		case 3:
			ret =  ret + "692";
			break;
		case 0:
			ret =  ret + "942";
			break;
	}
	//cout<<"i = "<<i<<", ret = "<<ret<<endl;
	return ret;
} 

string get(string input)
{
	if(input.size()<10)
	{
		unsigned int i;
		sscanf(input.c_str(), "%u", &i);
		//cout<<"i = "<<i<<endl;
		return get(i);
	}
	else
	{
		string head, end;
		size_t pos = input.size() - 6;
		head = input.substr(0, pos);
		end = input.substr(pos, input.size());
		unsigned int h, e, hr, er, ei, el;
		sscanf(head.c_str(), "%u", &h);
		sscanf(end.c_str(), "%u", &e);
		//cout<<"head = "<<head<<", h = "<<h<<endl;
		//cout<<"end = "<<end<<", e = "<<e<<endl;
		el = e%4;
		er=e*250;
		ei = e*250/1000000;
		hr = h*250+ei;
		//cout<<"el = "<<el<<", er = "<<er<<", ei = "<<ei<<", hr = "<<hr<<endl;	
		string rt = get(el);
		char ret[30];
		sprintf(ret, "%u %3u %s", hr, (er%1000000)/1000, rt.c_str());

		return ret;		
	}
}

int main()
{
	int tN;
	cin>>tN;
	vector<string> inputs;
	for(int i = 0; i<tN; i++)
	{
		string input;
		cin>>input;
		inputs.push_back(input);
	}
	for(int i =0; i<tN; i++)
	{
		cout<<get(inputs[i])<<endl;
	}
	/*cout<<get("123456789012")<<endl;
	for(int i=1; i<100; i++)
	{
		int ret = (i*10)+2;
		ret = ret*ret*ret;
		if((ret%1000)==888)
		{
			cout<<"The "<<j<<"th number is "<<(i*10+2)<<" and the ret = "<<ret<<endl;
			j++;
		}
	}
	cout<<get(100)<<endl;
	cout<<get(1001)<<endl;
	cout<<get(31002)<<endl;
	cout<<get(314503)<<endl;
	for(unsigned long i = 10; i< 3000; i++)
	{
		if((i*i*i)%1000==888)
		{
			cout<<"The "<<j<<"th number is "<<i<<endl;
			j++;
		}
	}*/
	return 0;
}
