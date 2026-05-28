class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // set of all characters must remain same
        // frequencies of characters (sorted) must remain same
        vector<uint32_t> freq(26*2, 0);
        for (char c : word1) {
            freq[c - 'a']++;
        }
        for (char c : word2) {
            freq[c - 'a' + 26]++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0 && freq[i + 26] != 0) {
                return false;
            } else if (freq[i + 26] == 0 && freq[i] != 0) {
                return false;
            }
        }
        sort(freq.begin(), freq.begin() + 26);
        sort(freq.begin() + 26, freq.end());
        for (int i = 0; i < 26; i++) {
            if (freq[i] != freq[i + 26]) {
                return false;
            }
        }
        return true;
    }
};