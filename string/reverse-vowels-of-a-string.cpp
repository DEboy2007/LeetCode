class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vowels;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                vowels.push_back(c);
            }
        }
        int i = vowels.size() - 1;
        while (i >= 0) {
            for (char &c : s) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                    c = vowels[i];
                    i--;
                }
            }
        }
        return s;
    }
};