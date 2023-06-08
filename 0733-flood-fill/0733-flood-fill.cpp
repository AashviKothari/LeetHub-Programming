class Solution {
public:

void dfs(vector<vector<int>> &mat, int row, int col, int iniColor, int color, int n, int m) {
    mat[row][col] = color; 
    
    if(row - 1 >= 0 and mat[row - 1][col] == iniColor and mat[row - 1][col] != color) {
        dfs(mat, row - 1, col, iniColor, color, n, m);
    }
    if(row + 1 < n and mat[row + 1][col] == iniColor and mat[row + 1][col] != color) {
        dfs(mat, row + 1, col, iniColor, color, n, m);
    }
    if(col - 1 >= 0 and mat[row][col - 1] == iniColor and mat[row][col - 1] != color) {
        dfs(mat, row, col - 1, iniColor, color, n, m);
    }
    if(col + 1 < m and mat[row][col + 1] == iniColor and mat[row][col + 1] != color) {
        dfs(mat, row, col + 1, iniColor, color, n, m);
    }
    return;
}

vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int color) {
    int iniColor = mat[sr][sc];
    int n = mat.size();
    int m = mat[0].size();
    dfs(mat, sr, sc, iniColor, color, n, m);
    
    return mat;
	}
};