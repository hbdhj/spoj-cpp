/* 3638
 Sample Input
 2
 a aa bb cc def ghi
 a a a a a bb bb bb bb c c	
 
 Sample Output
 3
 5
 */
#include <iostream>
#include <vector>

using namespace std;

#define LINE_LENGTH 1000
#define MAX_WORD 20

int main()
{
	int tN,i,j;
	vector<string> input;
	char line[LINE_LENGTH];
    cin.getline(line, LINE_LENGTH);
    sscanf(line, "%d", &tN);
	for(i=0; i<tN; i++)
	{
		cin.getline(line, LINE_LENGTH);
        input.push_back(line);
	}
    //input.push_back("a aa bb cc def ghi");
    //input.push_back("a a a a a bb bb bb bb c c");
    for(i=0;i<input.size();i++)
    {
        //cout<<input[i]<<endl;
        int sp=0;
        bool getChar = false;
        vector<int> legth;//(MAX_WORD,0);
        for(j=0;j<input[i].length();j++)
        {
            if(input[i][j]!=' ')
            {
                if(getChar==false)
                    sp=j;
                getChar=true;
            }
            else
            {
                if(getChar)
                {
                    getChar=false;
                    //cout<<j<<"-"<<sp<<", ";
                    legth.push_back(j-sp);
                }    
            }
                
        }
        //printf("L 58 %d\n", j-sp);
        legth.push_back(j-sp);

        int max=1;
        int consNum=1;
        //cout<<legth.size()<<endl;
        for(j=1;j<legth.size();j++)
        {
            //cout<<legth[j]<<", ";
            //printf("%d, ", legth[j]);
            if(legth[j]==legth[j-1])
                consNum++;
            else 
            {
                if(max<consNum)
                    max=consNum;
                consNum=1;
            }
                
        }
        //cout<<endl;
        if(max<consNum)
            max=consNum;
        printf("%d\n", max);
    }
}