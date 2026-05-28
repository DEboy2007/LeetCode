class Solution {
public:

    bool increasingTriplet(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        if (nums.size() <= 2) { return false; }
        int smallest = std::numeric_limits<int>::max();
        int secondSmallest = std::numeric_limits<int>::max();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= smallest) {
                smallest = nums[i];
            } else if (nums[i] <= secondSmallest) {
                secondSmallest = nums[i];
            } else {
                return true;
            }
        }
        return false;

    }
};