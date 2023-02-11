#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int fillCups(vector<int>amount)
{

    int head=0,end=2;
    sort(amount.begin(),amount.end());
    if(amount[0]+amount[1]<=amount[2])
    {
        return amount[2];
    }
    else
    {
        int count=0;
        count+=amount[1]-amount[0];
        amount[2]-=(amount[1]-amount[0]);
        count+=(amount[2]/2)*2;
        amount[0]-=amount[2]/2;
        count+=amount[0]+amount[2]2;
        return count;
    }


    /*
    no readme ,easy
    */










    // int count=0;
    // while(head!=end)
    // {
    //     if(amount[end]>amount[head])
    //     {
    //     count+=amount[head];
    //     amount[end]-=amount[head];  
    //     head++;
    //     }
    //     else
    //     {
    //         amount[head]-=amount[end];
    //         count+=amount[end];
    //         end--;
    //     }
    // }
    // count+=amount[head];
    // return count;
}
int main()
{
    vector<int> a{3,4,4};
    cout<<fillCups(a);
}