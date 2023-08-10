class Solution {
public:
int fun(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>> &dp){
    if(i>=dp.size()||j>=dp[0].size()) return 5e5;
    if(i==dp.size()-1&&j==dp[0].size()-1) {
        if(dungeon[i][j]<=0) return abs(dungeon[i][j])+1;
        else return 1;
    } 
    if(dp[i][j]!=-1) return dp[i][j];
    int up=fun(i+1,j,dungeon,dp);
    int down=fun(i,j+1,dungeon,dp);
    int minhealthreq=min(up,down)-dungeon[i][j];
    return dp[i][j]=(minhealthreq<=0)?1:minhealthreq;
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
       return fun(0,0,dungeon,dp); 
    }
};

// class Solution {
// public:
//     int calculateMinimumHP(vector<vector<int> > &dungeon) {
//         int M = dungeon.size();
//         int N = dungeon[0].size();
//         // hp[i][j] represents the min hp needed at position (i, j)
//         // Add dummy row and column at bottom and right side
//         vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
//         hp[M][N - 1] = 1;
//         hp[M - 1][N] = 1;
//         for (int i = M - 1; i >= 0; i--) {
//             for (int j = N - 1; j >= 0; j--) {
//                 int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
//                 hp[i][j] = need <= 0 ? 1 : need;
//             }
//         }
//         return hp[0][0];
//     }
// };