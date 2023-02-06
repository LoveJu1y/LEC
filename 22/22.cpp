#include<iostream>
#include<vector>
#include<string>
using namespace std;
string now="(";
vector<string> ret;
void op(int n,string now,int sul,int sur)
{
    if(sul<sur||sur>n||sul>n) return;
    if(sul==n&&sur==n)
     ret.push_back(now);
     if(sul+sur>2*n) return; 
     op(n,now+'(',sul+1,sur);
     op(n,now+')',sul,sur+1);
}
int main(void)
{
    int n=3;
    op(n,now,1,0);

    for(int i=0;i<ret.size();i++)
    {
        cout<<ret[i]<<"     ";
    }
}
//vector<string> generateParenthesis(int n) {
        
//         while(ret.size()!=0)
//         {
//             now.push_back('(');
//             sul++;
//             if(sul==sur&&sul==n/2)
//             {
//                 ret.push_back(now);
//             }
//             else{
//                 sul--;
//                 now.pop_back();
//             }
//             if();


//         }
// }