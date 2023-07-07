class Solution {
public:
    int helper(int i ,vector<int>& nums,int n, vector<int>&dp)
    {
        if(i>n)  return 0;      //base case
      
        if(dp[i]!=-1)return dp[i];  //check if already evaluated for that value of i

        int pick = nums[i]+ helper(i+2 ,nums ,n,dp);
        int notpick = helper(i+1,nums,n,dp);  //to skip that house
        return dp[i]=max(pick ,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        vector<int>dp(n,-1);  
        int fHouse = helper(0,nums,n-2,dp); //if we want to take first house
        for(int i=0;i<n;i++)
        {
            dp[i]=-1;  //changing values of dp back to -1 for storing notfirsthouse value
        }
        int notFirstHouse = helper(1,nums,n-1,dp); //if we want to take last house
        return max(fHouse,notFirstHouse);
    }
};