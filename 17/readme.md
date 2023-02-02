给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。

 

示例 1：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。

示例 2：

输入：nums = [0,0,0], target = 1
输出：0

来源：力扣（LeetCode）
[力扣16](https://leetcode.cn/problems/3sum-closest)
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    int size=nums.size();
    sort(nums.begin(),nums.end()); 
    int now=66699969;
    for(int i=0;i<size-2;i++)
    {
        int left=i+1,right=size-1;
        while(left<right){
            int x=nums[i]+nums[left]+nums[right];
            if(abs(x-target)<abs(now-target)) {now=x;}
            if(x<target) {left++;continue;}
            if(x>target) {right--;continue;}
            if(abs(x-target)<2) {return now;}
        }
    }
    return now;
    }
};
```
