class Solution {
public:
    string reverseWords(string s) {
        string currString = "";
        string result = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                // word done
                result += currString;
                currString = "";
            } else {
                // if first time seeing a new letter, add a space
                if (currString == "") {
                    currString += " ";
                }
                currString = s[i] + currString;
            }
        }
        // add last word (w/o space at end)
        result += currString;
        // remove trailing space
        return result.substr(0, result.length() - 1);
    }
};