class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> currRow(matrix[0].size(), 0);
        int maxRect = 0;
        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                currRow[c] = matrix[r][c] == '0' ? 0 : currRow[c] + (matrix[r][c] - '0');
            }
            stack<int> st;
            int rowRect = 0;
            for (int i = 0; i <= currRow.size(); i++) {
                int currHeight = (i == currRow.size()) ? 0 : currRow[i];
                while (!st.empty() && currRow[st.top()] >= currHeight) {
                    int popped = st.top(); st.pop();
                    int width = st.empty() ? i : i - st.top() - 1;
                    rowRect = max(rowRect, width * currRow[popped]);
                }
                st.push(i);
            }
            maxRect = max(maxRect, rowRect);
        }
        return maxRect;
    }
};