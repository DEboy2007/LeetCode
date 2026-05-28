class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // pick two highest frequencies with sliding window
        unordered_map<int, int> freq;
        int left = 0;
        int max = 0;
        for (int right = 0; right < fruits.size(); right++) {
            freq[fruits[right]]++;

            while (freq.size() > 2) {
                freq[fruits[left]]--;
                if (freq[fruits[left]] == 0) {
                    freq.erase(fruits[left]);
                }
                left++;
            }

            max = std::max(max, right - left + 1);
        }
        return max;
    }
};