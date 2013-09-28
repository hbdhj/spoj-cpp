/*
 TASK: Guess the Number
 */
#include <iostream>
#include <vector>

using namespace std;

#define UNIT_TEST

int initFactorVector(vector<vector<int> > &input)
{
	vector<int> check20, check18, check16, check15, check14, check12, check10, check9, check8, check6, check4;
	check20.push_back(20);
	check20.push_back(2);
	check20.push_back(4);
	check20.push_back(5);
	check20.push_back(10);
	input.push_back(check20);
	check18.push_back(18);
	check18.push_back(2);
	check18.push_back(3);
	check18.push_back(6);
	check18.push_back(9);
	input.push_back(check18);
	check16.push_back(16);
	check16.push_back(8);
	check16.push_back(4);
	check16.push_back(2);
	input.push_back(check16);
	check15.push_back(15);
	check15.push_back(5);
	check15.push_back(3);
	input.push_back(check15);
	check14.push_back(14);
	check14.push_back(7);
	check14.push_back(2);
	input.push_back(check14);
	check12.push_back(12);
	check12.push_back(6);
	check12.push_back(2);
	input.push_back(check12);
	check10.push_back(10);
	check10.push_back(5);
	check10.push_back(2);
	input.push_back(check10);
	check9.push_back(9);
	check9.push_back(3);
	input.push_back(check9);
	check8.push_back(8);
	check8.push_back(4);
	check8.push_back(2);
	input.push_back(check8);
	check6.push_back(6);
	check6.push_back(3);
	check6.push_back(2);
	input.push_back(check6);
	check4.push_back(4);
	check4.push_back(2);
	input.push_back(check4);
	
	return 0;
}

int dispFactorVector(vector<vector<int> > &input)
{
	for(int i = 0; i<input.size(); i++)
	{
		for(int j=0; j<input[i].size(); j++)
		{
			cout<<input[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool checkString(string str, vector<vector<int> > &check)
{
	bool ret = true;
	for(int i = 0; i<check.size(); i++)
	{
		cout<<"str.size = "<<str.size()<<endl;
		cout<<"check["<<i<<"][0] = "<<check[i][0]<<endl;

		if(str.size()>=check[i][0])
		{
			cout<<"more check ..."<<endl;
			if(str[check[i][0]-1]=='Y')
				for(int j = 1; j<check[i].size(); j++)
					if(str[check[i][j]-1]=='N')
						return false;
			else if(str[check[i][0]-1]='N')
			{
				for(int j = 1; j<check[i].size(); j++)
				{
					if(str[check[i][j]-1]=='Y')

				}
			}
		}
		else
			cout<<"skip ..."<<endl;
	}
	return ret;
}

int main()
{
	string input;
	vector<string> inputs;

#ifdef UNIT_TEST
	//inputs.push_back("YYNYY");
	//inputs.push_back("YYNNN");
	inputs.push_back("YYYNNN");
	//inputs.push_back("YYYYYYYYYYYYYYY");
	//inputs.push_back("YYNNNNNNNNNNNNN");
#else
	cin>>input;
	while(input!="*")
	{
		inputs.push_back(input);
		cin>>input;
	}
#endif
	vector<vector<int> > checkNum;
	initFactorVector(checkNum);
	//dispFactorVector(checkNum);
	for(int i = 0; i<inputs.size(); i++)
	{
		//cout<<inputs[i]<<endl;
		if(checkString(inputs[i], checkNum))
			cout<<"OK"<<endl;
		else
			cout<<"Not OK"<<endl;
	}
}
