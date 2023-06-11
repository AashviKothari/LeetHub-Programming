class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Check if the starting or ending cell is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        
        // Array to store the directions for 8 neighbors
        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        
        // Create a queue for BFS traversal
        queue<pair<int, int>> q;
        
        // Start from the top-left cell and mark it as visited
        q.push({0, 0});
        grid[0][0] = 1;
        
        // Perform BFS
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            // Check if reached the bottom-right cell
            if (x == n - 1 && y == n - 1) {
                return grid[x][y];
            }
            
            // Explore all 8 neighbors
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                // Check if the neighbor is within the grid boundaries
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    q.push({nx, ny});
                    grid[nx][ny] = grid[x][y] + 1;
                }
            }
        }
        
        // No clear path found
        return -1;
    }
};
