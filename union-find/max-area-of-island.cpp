class Solution {
public:

    int dfs(vector<vector<int>> &grid, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return 0;
        if (grid[row][col] == 0) return 0;
        grid[row][col] = 0;
        return 1 + dfs(grid, row, col + 1) 
                 + dfs(grid, row, col - 1) 
                 + dfs(grid, row + 1, col) 
                 + dfs(grid, row - 1, col);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        int max_v = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                max_v = std::max(dfs(grid, i, j), max_v);
            }
        }
        return max_v;
        
    }
};