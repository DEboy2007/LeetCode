// static const int fastio = []() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     return 0;
// }();

struct VectorHasher {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int i : v) {
            hash ^= std::hash<int>{}(i) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
    }
};

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<vector<int>, int, VectorHasher> freq;
        int result = 0;
        for (auto v : grid) {
            freq[v]++;
        }

        for (int j = 0; j < grid[0].size(); j++) {
            vector<int> v;
            for (int i = 0; i < grid.size(); i++) {
                v.push_back(grid[i][j]);
            }
            result += freq[v];
        }
        return result;
    }
};