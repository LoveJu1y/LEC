def maxSlidingWindow(nums: list[int], k: int) -> list[int]:
    #先尝试一下暴力解法吧，时间复杂度为o（n^2)
    # ret = []
    # n = len(nums)
    # for i in range(n-k+1):
    #     ret.append(max(nums[i:i+k]))
        
    # return ret
# 暴力法显然复杂度太高了，必须利用前一次计算的结果，多一次判断：
    ret = []
    n = len(nums)
    max_tmp = max(nums[0:k])
    ret.append(max_tmp)
    for i in range(n-k):
        if(max_tmp == nums[i]):
            max_tmp = max(nums[i+1:i+k+1])
        else:
            max_tmp = max_tmp if nums[i+k] <max_tmp else nums[i+k]
        ret.append(max_tmp)
        
    return ret
    
nums = [1,3,-1,-3,5,3,6,7]
print(maxSlidingWindow(nums,k = 3))