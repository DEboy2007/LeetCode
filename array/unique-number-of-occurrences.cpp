class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurences;
        for (int i : arr) {
            if (occurences.contains(i)) {
                occurences[i]++;
            } else {
                occurences[i] = 1;
            }
        }

        unordered_set<int> occurFreq;
        for (auto &[i, o] : occurences) {
            if (occurFreq.contains(o)) {
                return false;
            }
            occurFreq.insert(o);
        }
        return true;
        
    }
};