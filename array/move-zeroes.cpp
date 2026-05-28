class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // maintain two pointers i and j
        // move j to first nonzero number
        // once one is found, set nums[i] to nonzero and increment
        // once j is at end, put zeroes for rest of array
        std::cin.tie(nullptr);
        if (nums.size() <= 1) return;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (j < nums.size() && nums[j] == 0) {
                j++;
            }
            if (j == nums.size()) {
                return;
            }
            swap(nums[i], nums[j]);
            j++;
        }
        
    }
};