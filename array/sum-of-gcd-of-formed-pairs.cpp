class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            mx = max(nums[i], mx);
            nums[i] = gcd(nums[i], mx);
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            sum += gcd(nums[i], nums[j]);
            i++;
            j--;
        }
        return sum;
    }
};