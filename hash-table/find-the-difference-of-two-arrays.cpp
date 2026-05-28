enum State {
    NUMS1,
    NUMS2,
    BOTH
};

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        // answer[0] = nums1 - nums2
        // answer[1] = nums2 - nums1
        unordered_map<int, State> vecs;
        for (int i : nums1) {
            vecs[i] = State::NUMS1;
        }

        for (int i : nums2) {
            if (vecs.contains(i) && vecs[i] != State::NUMS2) {
                vecs[i] = State::BOTH;
            } else {
                vecs[i] = State::NUMS2;
            }
        }

        vector<vector<int>> result(2);

        for (auto &[i, s] : vecs) {
            if (s == State::NUMS1) {
                result[0].push_back(i);
            } else if (s == State::NUMS2) {
                result[1].push_back(i);
            }
        }
        return result;
    }
};