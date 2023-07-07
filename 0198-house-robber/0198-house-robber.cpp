class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        
        vector<int> dp(n, -1);
        return findMaxSum(nums, n - 1, dp);
    }
    
    int findMaxSum(vector<int>& nums, int n, vector<int>& dp) {
        if (n < 0)
            return 0;
        if (n == 0)
            return nums[0];
        
        if (dp[n] != -1)
            return dp[n];
        
        int include = nums[n] + findMaxSum(nums, n - 2, dp);
        int exclude = 0 + findMaxSum(nums, n - 1, dp);
        return dp[n] = max(include, exclude);
    }
};
