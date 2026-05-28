class Solution {
public:
    int compress(vector<char>& chars) {
        int typingAt = 0;
        for (int i = 0; i < chars.size(); i++) {
            char currChar = chars[i];
            int count = 0;
            while (i < chars.size() && chars[i] == currChar) {
                count++;
                i++;
            }
            string compressed(1, currChar);
            if (count != 1) compressed += to_string(count);
            for (char c : compressed) {
                chars[typingAt] = c;
                typingAt++;
            }
            i--;
        }
        int initSize = chars.size();
        for (int i = typingAt; i < initSize; i++) {
            chars.pop_back();
        }
        return chars.size();
    }
};