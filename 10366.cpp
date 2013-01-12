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

int day_month[] ={31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeapYear(int year)
{
    if((year%4==0)&&(year%100!=0))
        return true;
    else if(year%400==0)
        return true;
    else
        return false;
}


//get the days from 01/01/2000
int getdays(int year, int month, int day)
{
    int passed_years=year-2000;
    int passed_days=passed_years*365+passed_years/4-passed_years/100+passed_years/400;
    //Add the one more for 2000 is a leap year
    if(passed_years)
        passed_days++;
    //Add the one more for this leap year.
    if(isLeapYear(year)&&(month<2))
        passed_days--;
    if(month>1)
    while (--month) {
        passed_days+=day_month[month-1];
    }
    passed_days+=day;
    return passed_days;
}

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
        // prompt user for date
        scanf ("%d %d %d", &day, &month, &year);
        inputs[3*i]=year;
        inputs[3*i+1]=month;
        inputs[3*i+2]=day;
    }
    for(int i=0;i<n;i++)
    {    
        year=inputs[3*i];
        month=inputs[3*i+1];
        day=inputs[3*i+2];
        int passwd_days=getdays(year,month,day);
        printf ("%s\n", weekday[(passwd_days+5)%7]);
    }
    return 0;
}