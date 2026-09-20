class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            result += ('a' - s[i] + 26) * (i + 1);
        }
        return result;
    }
};