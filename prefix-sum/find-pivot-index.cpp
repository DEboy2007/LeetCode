class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // prefixSum[i]: sum of elements up to and including index i
        vector<int> prefixSum(nums.size());
        int runningTotal = 0;
        for (int i = 0; i < nums.size(); i++) {
            runningTotal += nums[i];
            prefixSum[i] = runningTotal;
        }
        runningTotal = 0;
        int pivot = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            runningTotal += nums[i];
            if (runningTotal == prefixSum[i]) {
                pivot = i;
            }
        }
        return pivot;
    }
};