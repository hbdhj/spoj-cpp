/*
Input:
1749870067
Output:
Sun Jun 13 16:20:39 2004
*/

#define DIVIDED 4000000007 

#include <ctime>
#include <iostream>
//#include <time.h>
 
int main()
{
    unsigned long long int input, sec_num;
    unsigned long long int divided=4000000007L;
    scanf("%llu", &input);
    sec_num=sqrt(input);
    /*while(sec_num*sec_num!=input)
    {
        input+=DIVIDED;
        sec_num=sqrt(input);
        printf("sec_num = %llu, input = %llu\n", sec_num, input);
    }*/
    unsigned long long int known = 1087143639;
    unsigned long long int div = known*known/divided;
    unsigned long long int remain = known*known%divided;
    printf("divided= %llu\n", divided);
    printf("known  = %llu\n", known);
    printf("div    = %llu\n", div);
    printf("remain = %llu\n", remain);
    time_t rawtime;
    struct tm * timeinfo;
    rawtime = sec_num;
    timeinfo = gmtime ( &rawtime );
    printf ( "The current date/time is: %s", asctime (timeinfo) );
}