class Solution {
public:
    bool solve(vector<int>& nums, int n, int sum, vector<vector<int>>& dp)
{
    if(sum==0)
    {
        return true;
    }
    if(n<0||sum<0)
    {
        return false;
    }
    if(dp[n][sum]!=-1)
        return dp[n][sum];
    
    bool exc=solve(nums,n-1,sum,dp);
    bool inc=solve(nums,n-1,sum-nums[n],dp);
    
    return dp[n][sum]=inc||exc;
}

//Tabulation
bool solveTab(vector<int>& nums, int n, int sum)
{
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0)); 
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(nums[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
    }
    return dp[n][sum];
}

bool canPartition(vector<int>& nums) {
    int n=nums.size();
    int sum=0;
    for(auto x: nums)
    {
        sum+=x;
    }
    if(sum%2)
        return false;
    int target=sum/2;
    // vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return solveTab(nums, n-1,target);
}
};