//vishwas-12
class Solution {
public:
    //MEMOIZATION   
    // int sol( int i, int j,vector<vector<int>> &dp,vector<vector<int>> &grid){
    //     if(i==0 && j==0) return grid[0][0];
    //     if(i<0 || j<0) return 1e5;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //         int up=grid[i][j]+sol(i,j-1,dp,grid);
    //      int left=grid[i][j]+sol(i-1,j,dp,grid);
    //     return dp[i][j]=min(up,left);
    // }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        //return sol(m-1,n-1,dp,grid);
        //TABULATION W/O S.O.   
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int up=grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else up+=1e5; //excluding this path as it wont be feasible
                    int left=grid[i][j];
                    if(j>0) left+=dp[i][j-1];
                    else left+=1e5; //excluding this path as it wont be feasible
                    dp[i][j]=min(left,up);
                }
            }
        }
        return dp[m-1][n-1];
    }
};