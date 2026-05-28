class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        int result = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] < k) {
                i++;
            } else if (nums[i] + nums[j] > k) {
                j--;
            } else {
                result++;
                i++;
                j--;
            }
        }
        return result;
    }
};