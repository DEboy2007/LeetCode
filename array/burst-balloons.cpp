class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        for (int size = 2; size < n + 2; size++) {
            for (int i = 0; i < n - size + 2; i++) {
                int mx = 0;
                int j = i + size;
                for (int k = i + 1; k < j; k++) {
                    int coins = nums[i] * nums[k] * nums[j];
                    mx = max(mx, coins + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = mx;
            }
        }
        return dp[0][n + 1];
    }
};