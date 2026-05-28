class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        while (i < n && s[i] == ' ') i++;
        if (i == n) return 0;
        bool neg = false;
        if (s[i] == '-') {
            neg = true;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        long long num = 0;
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            if (neg && -1 * num < (long) numeric_limits<int>::min()) {
                return numeric_limits<int>::min();
            }
            if (!neg && num > (long) numeric_limits<int>::max()) {
                return numeric_limits<int>::max();
            }
            i++;
        }
        return neg ? -1 * num : num;
    }
};