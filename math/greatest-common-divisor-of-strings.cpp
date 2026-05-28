class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1.length() < str2.length()) {
            return gcdHelper(str2, str1);
        }
        return gcdHelper(str1, str2);
    }

    string gcdHelper(string bigger, string smaller) {
        for (int i = smaller.length() + 1; i > 0; i--) {
            if (smaller.length() % i != 0) { continue; }
            string curr = smaller.substr(0, i);
            if (verify(smaller, curr) && verify(bigger, curr)) {
                return curr;
            }
        }
        return "";
    }

    bool verify(string bigger, string smaller) {
        if (bigger.length() % smaller.length() != 0) { return false; }
        for (int i = 0; i < bigger.length(); i += smaller.length()) {
            if (bigger.substr(i, smaller.length()) != smaller) {
                return false;
            }
        }
        return true;
    }
};