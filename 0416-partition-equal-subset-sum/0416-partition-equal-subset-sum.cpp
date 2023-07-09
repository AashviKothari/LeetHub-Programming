class Solution {
public:
    bool solve(int index,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(target==0){  return true;             }
        if(index==0){   return (arr[0]==target); }
        if(dp[index][target]!=-1)return dp[index][target];
        bool nottake=solve(index-1,target,arr,dp);
        bool take = false;
        if(target >= arr[index]){    take = solve(index-1,target-arr[index],arr,dp);    }
        return dp[index][target]= take | nottake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0,k;
        if(n==1)return false;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        k=sum;
        if(sum%2!=0){
            return false;
        }
        else{
            sum=sum/2;
            if(nums.size()==1)return false;
            vector<vector<int>>dp(n,vector<int>(sum+1,-1));
            return solve(n-1,sum,nums,dp);
        }
    }
};