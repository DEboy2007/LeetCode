class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        // add all rotten oranges
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                } if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int mins = 0;
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();
                for (auto [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if (nr < 0 || nc < 0 || nr >= m || nc >= n) {
                        continue;
                    } if (grid[nr][nc] != 1) {
                        continue;
                    } else {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            mins++;
        }

        if (fresh > 0) return -1;
        return mins;
        
    }
};