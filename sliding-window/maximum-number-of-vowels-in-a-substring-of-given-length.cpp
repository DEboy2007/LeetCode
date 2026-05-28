class Solution {
public:
    int maxVowels(string s, int k) {
        int bestNum = 0;
        int currNum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i < k) {
                currNum += vowel(s[i]) ? 1 : 0;
                bestNum += vowel(s[i]) ? 1 : 0;
            } else {
                currNum -= vowel(s[i - k]) ? 1 : 0;
                currNum += vowel(s[i]) ? 1 : 0;
                bestNum = max(currNum, bestNum);
            }
        }
        return bestNum;
    }

    bool vowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};