#include <iostream>
#include <vector>

using namespace std;

string getResult(string input)
{
	char digits[8], ret[8];
	int b1, b2;
	digits[7] = '\0';
	sscanf(input.c_str(), "%7c %d %d", digits, &b1, &b2);
	//cout<<"digits = "<<digits<<", b1 = "<<b1<<", b2 = "<<b2<<endl;
	int l = 0;
	int bs1 = 1;
	for(int i = 6; i>=0; i--)
	{
		if((digits[i]<='9')&&(digits[i]>'0'))
			l += (digits[i] - '0')*bs1;
		else if ((digits[i]>='A')&&(digits[i]<='F'))
			l += (digits[i] - 'A' + 10)*bs1;

		bs1 *= b1;
	}
	//cout<<"l = "<<l<<endl;
	int left = l;
	int bs2 = b2;
	char bit;
	ret[7] = '\0';
	for(int i=6; i>=0; i--)
	{
		bit = left%b2;
		if((b2>10)&&(bit>=10))
		{
			//cout<<"1 - "<<endl;
			//ret[i] = 'A' + bit - 10;
			ret[i] = 65 + bit - 10;
		}
		else if(left==0)
		{
			//cout<<" 2 -"<<endl;
			ret[i] = ' ';
		}
		else
		{
			//cout<<" 3 -"<<endl;
			ret[i] = '0' + bit;
		}
		left = (left - bit)/b2;
		//cout<<"bit = "<<(int)bit<<", left = "<<left<<", bs2 = "<<bs2<<endl;
		//cout<<"ret["<<i<<"] = "<<ret[i]<<" - " <<int(ret[i])<<endl;
		
	}
	string str = ret;
	//cout<<"str = "<<str<<endl; 
	if(left)
		return "  ERROR";
	else
		return str;
}

int main()
{
	vector<string> inputs;
	//cout<<'A'<<int('A')<<endl;
	inputs.push_back("1111000 2 10");
	inputs.push_back("1111000 2 16");
	inputs.push_back("2102101 3 10");
	inputs.push_back("2102101 3 15");
	inputs.push_back("  12312 4  2");
	inputs.push_back("     1A 15 2");
	inputs.push_back("1234567 10 16");
	inputs.push_back("   ABCD 16 15");
	for(int i = 0; i<inputs.size(); i++)
	{
		cout<<getResult(inputs[i])<<endl;
	} 
}
