class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0;
        int z = 0;
        int b = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) z++;

            while (z > 1) {
                if (nums[l] == 0) z--;
                l++;
            }

            b = max(b, r - l + 1);
        }

        return b - 1;
        
    }
};