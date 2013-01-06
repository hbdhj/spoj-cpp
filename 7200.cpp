#include <iostream>

using namespace std;

int getresult(int year, int month)
{
    if(month==(year/month))
    {
        int first
    }
    else if (month == 0)
    {
        int passed_secs = year * 3650;
        int left_secs = 295 - passed_secs % 295;
        return left_secs/10;
    }
};

int main()
{
    cout<<"hello"<<endl;
    int a = 3650;
    int b = 295;
    int c = a%b;
    int d = b%c;
    cout<<"c = "<<c<<", d = "<<d<<endl;
    while(c&&d)
    {
        if(d)
            c = c%d;
        //cout<<"c = "<<c<<", d = "<<d<<endl;    
        if(c)
            d = d%c;
        //cout<<"c = "<<c<<", d = "<<d<<endl;    
    }
    int ret = c>d?c:d;
    cout<<ret<<endl;
    int rep = a*b/ret;
    cout<<"rep days = "<<rep<<", years = "<<rep/a<<endl;
    return 0;
}