#include<iostream>
using namespace std;
int divide(int dividend, int divisor) {
        bool fu = (((dividend >> 31) ^ (divisor >> 31)));
        if(dividend > 0) dividend = -dividend;
        if(divisor > 0) divisor = -divisor;
        int mod = divisor;
        int minn = dividend >> 1;
        int now = -1;
        while(mod >= minn && mod >= (INT32_MIN >> 1)) {
            mod <<= 1;
            now <<= 1;
        }
        int ans = 0;
        while(dividend <= divisor){
            while(mod < dividend){
                mod >>= 1;
                now >>= 1;
            }
            while(dividend <= mod) {
                dividend -= mod;
                ans-=now;
            }
        }
        if(ans == -2147483648 && !fu) return 2147483647;
        return fu?-ans:ans;
    }
int main(void)
{
    int dividend = -115;
    int divisor = 3;
    cout<<divide(dividend,divisor);
}
