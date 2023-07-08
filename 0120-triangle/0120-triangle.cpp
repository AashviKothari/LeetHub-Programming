class Solution {
public:
int solve(int m, int n, vector<vector<int>> &triangle, int &target, vector<vector<int>> &dp){
    if(m == target){
        return triangle[m][n];
    }

    if(dp[m][n] != -1){
        return dp[m][n];
    }

    int down = triangle[m][n] + solve(m+1, n, triangle, target, dp);
    int diagonal = triangle[m][n] + solve(m+1, n+1, triangle, target, dp);

    return dp[m][n]=min(down, diagonal);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int target = triangle.size()-1;
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(0, 0, triangle, target, dp);
        
    }
};