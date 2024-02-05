def maxProfit( prices) -> int:
    n = len(prices)
    dp = [0 for i in range(n)]
    minin = prices[0]
    for i in range(1,n):
        minin = minin if minin < prices[i] else prices[i]
        dp[i] = dp[i-1] if dp[i-1]>(prices[i] - minin) else (prices[i] - minin)
    return dp[-1]
    
prices =[7,1,5,3,6,4]
print(maxProfit(prices))