/*
TASK: Rent your airplane and make money
Input:
1
4
0 5 10
3 7 14
5 9 7
6 9 8
Output:
18
*/
#include <iostream>
#include <vector>

using namespace std;

struct Order
{
    int start;
    int end;
    int earn;
};

struct RentPlan
{
    vector<Order> orders;
    int earn;
    int orderNum;
};

bool OrderCompare (Order i,Order j) { return (i.start<j.start); }

int main()
{
    int tN,i,j,k,m,n,s,e,c;
    scanf("%d", &tN);
    vector<int> orderNum;
    vector<vector<Order> > allorders;
    for(i=0;i<tN;i++)
    {
        scanf("%d", &n);
        vector<Order> orders;
        for(j=0;j<n;j++)
        {
            scanf("%d", &s);
            scanf("%d", &e);
            scanf("%d", &c);
            Order order;
            order.start =s;
            order.end =e;
            order.earn =c;            
            orders.push_back(order);
        }
        allorders.push_back(orders);
    }
    for(i=0;i<tN;i++)
    {
        sort(allorders[i].begin(), allorders[i].end(), OrderCompare); 
        n=allorders[i].size();
        //for(j=0;j<n;j++)
        //    cout<<allorders[i][j].start<<", "<<allorders[i][j].end<<", "<<allorders[i][j].earn<<endl;
        vector<RentPlan> rentPlans;
        RentPlan firstRentPlan;
        firstRentPlan.orders.push_back(allorders[i][0]);
        firstRentPlan.earn=allorders[i][0].earn;
        firstRentPlan.orderNum = 1;
        rentPlans.push_back(firstRentPlan);
        for(j=1;j<n;j++)
        {
            //cout<<"Now put "<<allorders[i][j].start<<", "<<allorders[i][j].end<<", "<<allorders[i][j].earn<<endl; 
            m=rentPlans.size();
            for(k=0;k<m;k++)
            {
                if(allorders[i][j].start>=rentPlans[k].orders[rentPlans[k].orderNum-1].end)
                {
                    rentPlans[k].orders.push_back(allorders[i][j]);
                    rentPlans[k].orderNum ++;
                    rentPlans[k].earn+=allorders[i][j].earn;
                }
            }
            if(m==k)
            {
                RentPlan rentPlan;
                rentPlan.orders.push_back(allorders[i][j]);
                rentPlan.earn=allorders[i][j].earn;
                rentPlan.orderNum = 1;
                rentPlans.push_back(rentPlan);
            }
        }
        int max=0;
        for(j=1;j<rentPlans.size();j++)
            if(max<rentPlans[j].earn)
                max=rentPlans[j].earn;
        printf("%d\n", max);        
    }
    return 0;
}
