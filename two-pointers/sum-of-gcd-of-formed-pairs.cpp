class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = nums[0];
        vector<int> gcds(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            mx = max(nums[i], mx);
            gcds[i] = gcd(nums[i], mx);
        }
        sort(gcds.begin(), gcds.end());
        long long sum = 0;
        int i = 0;
        int j = gcds.size() - 1;
        while (i < j) {
            sum += gcd(gcds[i], gcds[j]);
            i++;
            j--;
        }
        return sum;
    }
};