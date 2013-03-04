/*
7757. Flowers Flourish from France
Sample input
Flowers Flourish from France 
Sam Simmonds speaks softly
 Peter pIckEd pePPers
truly tautograms triumph
this is NOT a tautogram
*
Output for the sample input
Y
Y
Y
Y
N
*/
#include <stdio.h>
#include <iostream>
//#include <vector>

using namespace std;

int main()
{
    char line[1200];
    cin.getline(line, 1200);
    while(line[0]!='*')
    {
        int mark[26];
        string str=line; 
        int len=str.length();
        int header=0;
        while(str[hear]==' ')
        {
            header++;
        }
        int tailer=len-1;
        while(str[tailer]==' ')
        {
            tailer--;
        }
        str=str.substr(header,tailer-header);
        printf("%s",str.c_str());
        cin.getline(line, 1200);
    }
    return 0;
} 