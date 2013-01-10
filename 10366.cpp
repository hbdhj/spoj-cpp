/*
10366. Play with Dates
Sample Input:
3
11 1 2012
12 1 2012
13 1 2012
Sample Output:
Wednesday
Thursday
Friday
*/

#include <stdio.h>
#include <time.h>
#include <vector>

using namespace std;

int main ()
{
    int year, month ,day, n;
    char * weekday[] = { "Sunday", "Monday",
                       "Tuesday", "Wednesday",
                       "Thursday", "Friday", "Saturday"};
    scanf ("%d", &n);                   
    vector<int> inputs(3*n);
    for(int i=0;i<n;i++)
    {
        /* prompt user for date */
        scanf ("%d %d %d", &day, &month, &year);
        inputs[3*i]=year;
        inputs[3*i+1]=month;
        inputs[3*i+2]=day;
    }
    for(int i=0;i<n;i++)
    {    
        time_t rawtime;
        struct tm * timeinfo;
        /* get current timeinfo and modify it to the user's choice */
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        timeinfo->tm_year = inputs[3*i] - 1900;
        timeinfo->tm_mon = inputs[3*i+1] - 1;
        timeinfo->tm_mday = inputs[3*i+2];

        /* call mktime: timeinfo->tm_wday will be set */
        mktime ( timeinfo );

        printf ("%s.\n", weekday[timeinfo->tm_wday]);
    }
    return 0;
}