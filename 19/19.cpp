#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
    vector<int>nums{1,0,-1,0,-2,2};
    vector <vector<int>>ret;
    int target=0;
    sort(nums.begin(),nums.end());
    int i,j;
    int len=nums.size();
    if(len<4)return ;//ret;
    if(target>0&&nums[len-1]<target/4) return ;//ret;
    if(target<0&&nums[0]>0) return ;//ret;
    for( i=0;i<len-3;i++)
    {
        if(target>0&&nums[i]>target) break;
        for(j=i+1;j<len-2;j++)
        {
            double now=(double)target-(double)nums[i]-(double)nums[j];
            int left=j+1,right=len-1;
            if(nums[j]>0&&nums[j]>now) break;
            while(left<right)
            {
                if(nums[left]+nums[right]>now)
                {right--;while(left<right&&nums[right]==nums[right+1]){right--;}continue;}
                if(nums[left]+nums[right]<now)
                {left++;while(left<right&&nums[left]==nums[left-1]){left++;}continue;}
                else {
                    ret.push_back({nums[i],nums[j],nums[left],nums[right]});
                    left++;while(left<right&&nums[left]==nums[left-1]){left++;}
                    right--;while(left<right&&nums[right]==nums[right+1]){right--;}
                }
                
            }
            while(j<len-2&&nums[j]==nums[j+1])j++;
                
        }while(i<len-3&&nums[i]==nums[i+1])i++;
        
    }
}