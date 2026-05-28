class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows > s.length() || numRows == 1) return s;
        string result;
        for (int row = 1; row <= numRows; row++) {
            int currIndex = row - 1;
            int gap1 = ((numRows - row) * 2) == 0 ? (2 * numRows - 2) : ((numRows - row) * 2);
            int gap2 = (row - 1) * 2 == 0 ? (2 * numRows - 2) : (row - 1) * 2;
            bool gap = true;
            while (currIndex < s.length()) {
                result += s[currIndex];
                if (gap) {
                    currIndex += gap1;
                    gap = false;
                } else {
                    currIndex += gap2;
                    gap = true;
                }
            }
        }
        return result;
    }
};