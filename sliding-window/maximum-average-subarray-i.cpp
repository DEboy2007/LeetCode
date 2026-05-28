class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        int j = k;
        double currAvg = 0;
        for (int init = 0; init < k; init++) {
            currAvg += nums[init];
        }
        double bestAvg = currAvg;
        while (j < nums.size()) {
            currAvg -= nums[j - k];
            currAvg += nums[j];
            bestAvg = max(bestAvg, currAvg);
            j++;
        }
        return bestAvg / k;
    }
};