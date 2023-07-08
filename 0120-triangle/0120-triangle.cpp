class Solution {
public:
// int solve(int m, int n, vector<vector<int>> &triangle, int &target, vector<vector<int>> &dp){
// //     if(m == target){
// //         return triangle[m][n];
// //     }

// //     if(dp[m][n] != -1){
// //         return dp[m][n];
// //     }

// //     int down = triangle[m][n] + solve(m+1, n, triangle, target, dp);
// //     int diagonal = triangle[m][n] + solve(m+1, n+1, triangle, target, dp);

// //     return dp[m][n]=min(down, diagonal);
// // }
    int minimumTotal(vector<vector<int>>& triangle) {
        // int target = triangle.size()-1;
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
   for(int j=0; j<n; j++) dp[n-1][j]=triangle[n-1][j];
        
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i; j>=0; j--)
            {
                int d=dp[i+1][j]+triangle[i][j];
                int dg=dp[i+1][j+1]+triangle[i][j];
                
                dp[i][j]=min(d,dg);
            }
        }
        return dp[0][0];
        // return solve(0, 0, triangle, target, dp);
        
    }
};