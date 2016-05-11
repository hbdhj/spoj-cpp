//
//  14890_GOODD.cpp
//
//
//  Created by Haijun Deng on 13-5-22.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//
/*
 TASK: Good Code
 Input:
12 4
c++;
goto 6;
18:
c++;
c++;
goto 2;
goto 6;
6:
goto 18;
2:
c++;
c++;
 Output:
 11
 Explanation of Sample:
 The program will run through the following lines, and corresponding values of c:

 Line 1 ("c++;"), c=1
 Line 2 ("goto 6;"), c=1
 Line 8 ("6:"), c=1
 Line 9 ("goto 18;"), c=1
 Line 3 ("18:"), c=1
 Line 4 ("c++;"), c=2
 Line 5 ("c++;"), c=3
 Line 6 ("goto 2;"), c=3
 Line 10 ("2:"), c=3
 Line 11 ("c++;"), c=4
 As can be seen, c first achieves a value of M=4 on line 11.
 */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int N, M;
    string tmp;
    cin>>N>>M;
    getline(cin, tmp);
    vector<string> lines;
    int lineN=N;
    while (N--)
    {
        string line;
        getline(cin, line);
        lines.push_back(line);
    }
    map<int, vector<int> > program;
    int s_sectionId=0;

    for (int i=0;i<lineN;i++)
    {
        printf("%d - %s\n", i+1, lines[i].c_str());
        if(lines[i][lines[i].length()-1]==':')
        {
            //printf("line %d - %s is a section begin line\n", i+1, lines[i].c_str());
            sscanf(lines[i].c_str(),"%d:",&s_sectionId);
            vector<int> section;
            program.insert(pair<int, vector<int> >(s_sectionId, section));
        }
        else if(lines[i][0]=='c')
        {
            //printf("line %d - %s is count line\n", i+1, lines[i].c_str());
            program[s_sectionId].push_back(i+1);
        }
        else if(lines[i][0]=='g')
        {
            //printf("line %d - %s is switch line\n", i+1, lines[i].c_str());
            int t_sectionId=0;
            sscanf(lines[i].c_str(),"goto %d;",&t_sectionId);
            if(program[s_sectionId].size())
            {
                if(program[s_sectionId][program[s_sectionId].size()-1]>0)
                    program[s_sectionId].push_back(0-t_sectionId);
            }
            else
                program[s_sectionId].push_back(0-t_sectionId);
        }
        else
        {
            printf("ERROR line %d is unacceptable '%s'", i+1, lines[i].c_str());
        }
    }
    map<int, vector<int> >::iterator it;
    for (it=program.begin();it!=program.end();++it)
    {
        printf("Section %d:\n", it->first);
        for(int i=0;i<it->second.size();i++)
        {
            if(it->second[i])
                printf("%d ", it->second[i]);
            else
                printf(" will go to section %d", 0-(it->second[i]));
        }
        printf("\n");
    }
    return 0;
}
