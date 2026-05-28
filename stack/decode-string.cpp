class Solution {
public:
    string decodeString(string s) {
        string result;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                int k = 0;
                while (isdigit(s[i])) {
                    k = k * 10 + (s[i] - '0');
                    i++;
                }
                string portion;
                i++; // skip [
                int count = 1;
                while (i < s.length()) {
                    if (s[i] == '[') count++;
                    else if (s[i] == ']') count--;
                    if (count == 0) break;
                    else portion.push_back(s[i]);
                    i++;
                }
                string decoded = decodeString(portion);
                for (int j = 0; j < k; j++) {
                    result += decoded;
                }
            } else if (c == ']') {
                continue;
            } else {
                result += c;
            }
        }
        return result;  
    }
};