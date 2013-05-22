/*
TASK: Bingo round 2
*/
#include <stdio.h>

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

#define ROW 5
#define COL 5

int main()
{
	unsigned int seed;
	cin>>seed;
	cout<<"B  I  N  G  O"<<endl;
	//default_random_engine generator;
	//uniform_int_distribution<int> distribution(0,9);
	srand(seed);
	for(int i=0;i<ROW;i++)
	{
		int randumNum = 0;
		vector<int> randomlist(10, 0);
		while(randumNum<COL)
		{
			int dice_roll = rand()%10;
			//printf("dice_roll = %d\n", dice_roll);
			if(dice_roll>=0&&dice_roll<=9)
			{
				if(randomlist[dice_roll]==0)
				{
					randomlist[dice_roll]=1;
					randumNum++;
				}
			}
		}
		for(int j=0;j<10;j++)
		{
			if(randomlist[j])
			{
				printf("%-3d", j+1+i*10);
			}
		}
		printf("\n");
	}
	return 0;
}
