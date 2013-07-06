/*
 TASK: Find the Clone
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	vector<map<string, int> >  inputs;
	vector<int> persons;
	while((m!=0)&&(n!=0))
	{
		persons.push_back(n);
		map<string, int> clones;
		for(int i=0;i<n;i++)
		{
			string dna;
			cin>>dna;
			map<string, int>::iterator it = clones.find(dna);
			if(it==clones.end())
				clones[dna]=0;
			else
				clones[dna]++;
		}
		inputs.push_back(clones);
		cin>>n;
		cin>>m;
	}
	for(int i=0;i<inputs.size();i++)
	{
		map<string, int>::iterator it;
		vector<int> res(persons[i], 0);
		for (it=inputs[i].begin() ; it != inputs[i].end(); it++ )
			res[(*it).second]++;
		for(int j=0;j<res.size();j++)
			cout<<res[j]<<endl;
	}
	return 0;
}
