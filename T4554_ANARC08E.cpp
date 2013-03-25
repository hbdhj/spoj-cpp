/*4554*/
#include <iostream>
#include <vector>

using namespace std;

unsigned long long int fact(int n)
{
    unsigned long long int ret=1;
    int init=2;
    while(init<=n)
    {
        ret*=init;
        init++;
    }
    return ret;
}
int main()
{
    /*cout<<fact(1)<<endl;
    cout<<fact(2)<<endl;
    cout<<fact(3)<<endl;
    cout<<fact(4)<<endl;
    cout<<fact(5)<<endl;
    cout<<fact(6)<<endl;*/
    int t1,t2,sum,i;
    unsigned long long p;
    cin>>t1;
    cin>>t2;
    vector<int> input;
    while((t1!=-1)&&(t2!=-1))
    {
        input.push_back(t1);
        input.push_back(t2);
        cin>>t1;
        cin>>t2;
    }
    
    for(i=0;i<input.size()/2;i++)
    {
        t1=input[2*i];
        t2=input[2*i+1];
        sum=t1+t2;
        cout<<t1<<"+"<<t2;
        if((t1!=0)&&(t2!=0))
        {
            p=fact(t1+t2)/fact(t1)/fact(t2);
            if(p==sum)
                cout<<"="<<sum<<endl;
            else
                cout<<"!="<<sum<<endl;            
        }
        else
        {
            cout<<"="<<sum<<endl;
        }
    }
	return 0;
}