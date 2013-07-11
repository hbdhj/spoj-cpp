/*
TASK: Assistance Required
Input:
1
2
10
20
0
Output:
2
3
29
83
*/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <list>
using namespace std;

int res[4000];

int contruct()
{
    //const int num=100000;
	const int num=30000;
	std::list<int> mylist(num,2);
    std::list<int>::iterator it=mylist.begin();
    ++it;
    int i=1;
    for(; it!=mylist.end(); ++it)
    {
        *it=i*2+1;
        i++;
    }
    
    /*for(it=mylist.begin();it!=mylist.end(); ++it)
    {
        printf("%d ", *it);
    }
    printf("\n");*/
    it=mylist.begin();
    ++it;
    for(; it!=mylist.end(); ++it)
    {
        //printf("Now remove the next %d numbers\n", *it);
        std::list<int>::iterator it2=it;
        ++it2;
        int check=0;
        for(;it2!=mylist.end(); )
        {
            check++;
            //printf("*it=%d, *it2=%d, check=%d\n", *it,*it2,check);
            if(check%(*it)==0)
            {
                //printf("remove %d\n",*it2);
                std::list<int>::iterator it3=it2;
                advance(it2,1);
                mylist.erase(it3);
            }
            else
                advance(it2,1);
        }
        /*it2=mylist.begin();
        for(it2=mylist.begin();it2!=mylist.end();it2++)
        {
            printf("%d ", *it2);
        }
        printf("\n");*/
	}
    /*printf("There are %d elements in list\n", mylist.size());
    for(it=mylist.begin(); it!=mylist.end(); ++it)
    {
        printf("%d ", *it);
    }
    printf("\n");*/
    int id=0;
    for(it=mylist.begin(); it!=mylist.end()&&id<4000; ++it)
    {
        res[id]=*it;
        id++;
    }
    return 0;
}

int main()
{
	contruct();
    int n;
    scanf("%d",&n);
    while(n)
    {
        printf("%d\n",res[n-1]);
        scanf("%d",&n);
    }
    return 0;
}
