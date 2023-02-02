#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int num[]={-1,0,1,2,-1,-4};

vector <vector<int> >ret;
int target=2;
int main(void)


{
    vector<int>nums(num,num+6); int size=nums.size();
    sort(nums.begin(),nums.end());
    for(int i=0;i<size-2;i++)
    {
        int now=66699969;
        int left=i+1,right=size-1;
        while(left<right){
            if(abs(nums[i]+nums[left]+nums[right]-target)<abs(now-target)) 
            {
                if(!ret.empty()) 
                    ret.pop_back();  
                ret. push_back({nums[i],nums[left],nums[right]});
                now=nums[i]+nums[left]+nums[right];
                // if(nums[i]+nums[left]+nums[right]<target) now=nums[i]+nums[left++]+nums[right];
                // if(nums[i]+nums[left]+nums[right]>target) now=nums[i]+nums[left]+nums[right--];
                // if(nums[i]+nums[left]+nums[right]==target) cout<<now;
            }
            if(nums[i]+nums[left]+nums[right]<target) {left++;continue;}
            if(nums[i]+nums[left]+nums[right]>target) {right--;continue;}
            if(nums[i]+nums[left]+nums[right]==target) {cout<<now;}
        }

    }


}