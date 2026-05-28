class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int currZeroes = 0;
        int best = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                currZeroes++;
            }

            while (currZeroes > k) {
                if (nums[l] == 0) currZeroes--;
                l++;
            }

            best = max(best, r - l + 1);
        }
        return best;
    }
};