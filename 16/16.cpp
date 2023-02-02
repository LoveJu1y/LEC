#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
/// LEETCODE 16
/// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
// 你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。


// 示例 1：
// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 解释：
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
// 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
// 注意，输出的顺序和三元组的顺序并不重要。

// 示例 2：

// 输入：nums = [0,1,1]
// 输出：[]
// 解释：唯一可能的三元组和不为 0 。

// 示例 3：

// 输入：nums = [0,0,0]
// 输出：[[0,0,0]]
// 解释：唯一可能的三元组和为 0 。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/3sum
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
// /// @return 

 vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());//先排个序
        // std::sort(nums.begin(),nums.end());
    vector<vector<int>>ret; 
    int head=0;
    int end=nums.size()-1;
    int k;//循环中的索引变量
    int hhh=0;
    int end_k=end;
    int head_k=head;
    int c=(end+head)/2;
    //思路是，确定首head尾end，在中间查找，在右移head，一步一步找
    while(1)
    {
        while (1) {// 使用head_k，是为了二分查找确定范围，而end_k也是，但他还可以用作下一次查找的k的边界
            c=(head_k+end_k)/2;
            if(head_k+1>=end_k)
            break;
            if(nums[c]+nums[head]+nums[end]==0)
            {
                end_k=c;
                ret.push_back(vector<int>{nums[head],nums[c],nums[end]});
                break;
            }
            if(nums[c]+nums[head]+nums[end]>0)
            {
                end_k=c;continue;
            }
            if(nums[c]+nums[head]+nums[end]<0)
            {
                head_k=c;continue;
            }
        }
        while(head<end_k&&nums[head]==nums[head+1])//跳过相同的head（左边界）
            head++;
        head++;
        head_k=head;
        if(nums[head]>0||head+1>=end_k)//说明这个end已经结束了
        {
            while(end>=1&&nums[end]==nums[end-1])
                end--;
            end--;
            head_k=head=0;//从头开始
            end_k=end;
        }
        if(head>end||end_k<1||nums[end]<0)//如果有越界，或者end小于零，可以结束了
            break;
    }
     return ret;
        }

void next(char *P,int N[])//在kmp算法中对模式串进行处理
{
    int m=strlen(P);
    N[0]=0;
    int i=1,j=0;;;;
    while(i<m)//也就是，i表示当前所在位置，
    {
        if(P[i]==P[j])
        {
            N[i++]=j+1;
            j++;
        }
        else if(j>0) j=N[j-1];
        else N[i++]=0;
    }
}
int main(void)
{
    int n;
    cin>>n;
    long long int f=1,g=0;
    while(n-->0)
    {
        g+=f;
        f=g-f;
    }
    cout<<g;
}