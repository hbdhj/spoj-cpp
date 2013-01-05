/* 3261 Race against Time */

#include <iostream>
#include <vector>

using namespace std;

#define LINE_LENGTH 50
//#define unsigned int unsigned long

struct Query
{
	bool action;	//true - M, false - C
	unsigned int u1;	// i for M, P for C
	unsigned int u2;	// X for M, Q for C
	unsigned int u3;	// no for M, X for C
};

int main()
{
	char input[LINE_LENGTH];
	cin.getline(input, LINE_LENGTH);
	unsigned int CowNum, QueryNum;
	cout<<input<<endl;
	sscanf(input, "%u %u", &CowNum, &QueryNum);
	cout<<CowNum<<", "<<QueryNum<<endl;
	vector<unsigned long> cowId;
	for(unsigned int i = 0; i<CowNum; i++)
	{
		cin.getline(input, LINE_LENGTH);
		unsigned int CowId;
		sscanf(input, "%u", & CowId);
		cout<<"The "<<i<<"the cow's id ="<<CowId <<endl;
		cowId.push_back(CowId);
	}
	vector<Query> cowQuery;
	for(unsigned int i = 0; i<QueryNum; i++)
	{
		cin.getline(input, LINE_LENGTH);
		
		unsigned int u1, u2, u3;
		bool act;
		char c_act[1];
		Query query;
		if(input[0]=='M')
		{
			sscanf(input, "%c %u %u", c_act, &u1, &u2);
			cout<<"u1 = "<<u1<<", u2 = "<<u2<<endl;
			query.action = true;
			query.u1 = u1;
			query.u2 = u2;
			query.u3 = 0;
		}
		else
		{
			sscanf(input, "%c %u %u %u", c_act, &u1, &u2, &u3);
			cout<<"u1 = "<<u1<<", u2 = "<<u2<<", u3 = "<<u3<<endl;
			query.action = false;
			query.u1 = u1;
			query.u2 = u2;
			query.u3 = u3;
		}
		cowQuery.push_back(query);
	}
	for(unsigned long i = 0; i<QueryNum; i++)
	{
		if(cowQuery[i].action)
		{
			cowId[cowQuery[i].u1] = cowQuery[i].u2;
		}
		else
		{
			unsigned long count = 0;
			for(unsigned long l = cowQuery[i].u1 - 1 ; l < cowQuery[i].u2; l++)
			{
				if(cowId[l]<=cowQuery[i].u3)
					count++;
			}
			cout<<cout<<endl;
		}
	}
}
