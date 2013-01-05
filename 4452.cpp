/* 
Deng Haijun 2012/12/17
4452. Simple Arithmetics II
Input:
4
1 + 1 * 2 =
29 / 5 =
103 * 103 * 5 =
50 * 40 * 250 + 791 =
Output:
4
5
53045
500791
*/

#include <iostream>
#include <vector>

#define LINE_LENGTH 1000

using namespace std;

long long int getArithmeticsResult(string input)
{
	size_t l_pos = 0;
	size_t r_pos = input.size();
	while(input[l_pos]==' ')
		l_pos++;
	while(input[r_pos]==' ')
		r_pos--;
	if(input[r_pos-1]=='=')
		r_pos--;
	input = input.substr(l_pos, r_pos);
	size_t pos1= input.rfind('+');
	size_t pos2= input.rfind('-');
	size_t pos3= input.rfind('*');
	size_t pos4= input.rfind('/');
	size_t pos = 0;
	if((pos1>pos)&&(pos1!=string::npos))
		pos = pos1;
	if((pos2>pos)&&(pos2!=string::npos))
		pos = pos2;
	if((pos3>pos)&&(pos3!=string::npos))
		pos = pos3;
	if((pos4>pos)&&(pos4!=string::npos))
		pos = pos4;

	string left, right;
	if(pos!=0)
	{
		left = input.substr(0, pos);
		right = input.substr(pos+1, input.size());
	}
	if(pos==pos1)
	{
		return  getArithmeticsResult(left)+ getArithmeticsResult(right);
	}
	
	else if(pos==pos2)
	{
		return  getArithmeticsResult(left)- getArithmeticsResult(right);
	}
	else if(pos==pos3)
	{
		return  getArithmeticsResult(left)* getArithmeticsResult(right);
	}
	else if(pos==pos4)
	{
		return  getArithmeticsResult(left)/ getArithmeticsResult(right);
	}
	else if(pos==0)
	{
		long long int r;
		sscanf(input.c_str(), "%lld", &r);
		return r;
	}
	return 0;
}

int main()
{
	char input[LINE_LENGTH];
	cin.getline(input, LINE_LENGTH);
	int testCaseNum;
	sscanf(input, "%d", & testCaseNum);
	vector<string> Arithmetics;
	for(int i = 0; i<testCaseNum; i++)
	{
		cin.getline(input, LINE_LENGTH);
		unsigned int CowId;
		//string arithmetic = input;
		Arithmetics.push_back(input);
	}
	for(int i = 0; i<Arithmetics.size(); i++)
	{
		cout<<getArithmeticsResult(Arithmetics[i])<<endl;
	}
	return 0;
}
