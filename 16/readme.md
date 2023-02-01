# LEETCODE 16
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：

输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。

 

提示：

    3 <= nums.length <= 3000
    -105 <= nums[i] <= 105

## 官方题解

```c++
 vector<vector<int>> threeSum(vector<int>& nums) {
      int size_nums = nums.size();
      vector<vector<int>> ans;//最终返回的答案
      sort(nums.begin(), nums.end(), less<int>());//参数，表示从小到大排序
      for(int i = 0; i < size_nums-2; ++i){
        if(i && nums[i] == nums[i-1])//i不等于0并且，num[i]与前一个相同，就跳过就行了，我那个也是，不过是和后一个比较，限制的是end
        continue;
        int x = nums[i];
        if(x + nums[i+1] + nums[i+2] > 0)//说明太大，可以结束了
            break;
        if(x + nums[size_nums-2] + nums[size_nums-1] < 0)//说明太小，继续右移
            continue;
            int left = i + 1, right = size_nums - 1;
        while(left < right){
        int t = nums[left] + nums[right] + x;
        if(t > 0){
            --right;
        }else if (t < 0){
            ++left;
        }else{
            ans.emplace_back(vector<int>{x, nums[left], nums[right]});
            ++left;
            while(left < right && nums[left] == nums[left-1]) ++left;
            --right;
            while(left < right && nums[right] == nums[right+1]) --right;
        }
        }
    }
      return ans;
    }
```

- 首先，他这里使用的变量实际上只有left和right两个，它是在i+1到最后所有元素中寻找两个，关键就在于： 
        if(t > 0){
            --right;
        }else if (t < 0){
            ++left;
 - 他本质上，时间复杂度是，n*n,在大循环外，假设情况比较坏，第一次，得便利全部，n个，第二次n-1，...这样下去反复，求和也就是n^2,我的方法呢？假设情况比较坏，相当于，固定最后一个，第一个，中间找n个，head前进，n-1，最终下来是n^3,没法比，就算用了二分查找，把查找的时间降到对数，也依然远高于n^2.

