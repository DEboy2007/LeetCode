class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string final;
        int i = 0;
        while (i < word1.length() && i < word2.length()) {
            final += word1[i];
            final += word2[i];
            i++;
        }
        if (i >= word1.length()) {
            for (int j = i; j < word2.length(); j++) {
                final += word2[j];
            }
        }
        if (i >= word2.length()) {
            for (int j = i; j < word1.length(); j++) {
                final += word1[j];
            }
        }
        return final;
        
    }
};