class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int i = 0;
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            nums[j] = curr;
            while (i < nums.size() && nums[i] == curr) {
                i++;
            }
            i--;
            j++;
        }
        return j;
    }
};