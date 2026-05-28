class Solution {
public:

    void dfs(vector<vector<int>> &image, int r, int c, int color, int originalColor) {
        int m = image.size();
        int n = image[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n) {
            return;
        } if (image[r][c] != originalColor) {
            return;
        } else {
            image[r][c] = color;
            dfs(image, r + 1, c, color, originalColor);
            dfs(image, r, c + 1, color, originalColor);
            dfs(image, r - 1, c, color, originalColor);
            dfs(image, r, c - 1, color, originalColor);
        }
    }

    void bfs(vector<vector<int>> &image, int r, int c, int color) {
        deque<pair<int, int>> q;
        q.push_back({r, c});
        int original_color = image[r][c];
        image[r][c] = color;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop_front();

            for (auto [cr, cc] : dirs) {
                int nr = row + cr;
                int nc = col + cc;
                if (nr < 0 || nc < 0 || nr >= image.size() || nc >= image[0].size()) {
                    continue;
                } if (image[nr][nc] != original_color) {
                    continue;
                } else {
                    image[nr][nc] = color;
                    q.push_back({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if (image[sr][sc] == color) return image;
        int originalColor = image[sr][sc];
        dfs(image, sr, sc, color, originalColor);
        return image;
    }
};