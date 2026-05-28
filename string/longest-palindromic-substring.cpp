class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        int longestLen = 0;
        int longestI = 0;
        int longestJ = 0;
        vector<char> lastCol(s.length(), true);
        vector<char> thisCol(s.length(), true);
        for (int col = 0; col < thisCol.size(); col++) {
            for (int row = 0; row <= col; row++) {
                if (col - row <= 1) {
                    thisCol[row] = (s[row] == s[col]);
                } else {
                    thisCol[row] = (lastCol[row + 1] && s[row] == s[col]);
                }
                if (thisCol[row] && (col - row + 1) > longestLen) {
                    longestLen = col - row + 1;
                    longestI = row;
                    longestJ = col;
                }
            }
            swap(lastCol, thisCol);
        }
        return s.substr(longestI, longestJ - longestI + 1);
    }
};