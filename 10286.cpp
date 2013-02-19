/*
10286. DOTA HEROES
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	/* Testcases, heroes, towers, damage */
	int T, h, t, d, i, *max, list[500];
	cin >> T;
	while(T>0)
    {
		cin >> h >> t >> d;
		for(i=0;i<h;i++)
			cin >> list[i];

		while(t>0)
        {
			max = max_element(list, list+h);
			if(d>=*max)
				break;
			*max = *max-d;
			t--;
		}

		(t==0) ? cout << "YES" : cout << "NO";
		cout << endl;
		T--;
	}
}