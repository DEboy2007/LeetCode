class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adjList;
        for (auto& v : tickets) {
            adjList[v[0]].push_back(v[1]);
        }
        for (auto& [key, v] : adjList) {
            sort(v.begin(), v.end());
        }
        vector<string> currPath;
        vector<string> circuit;
        unordered_map<string, int> activeIndex;
        currPath.push_back("JFK");

        while (!currPath.empty()) {
            string node = currPath.back();
            if (adjList.contains(node) && activeIndex[node] < adjList[node].size()) {
                string next = adjList[node][activeIndex[node]];
                activeIndex[node]++;
                currPath.push_back(next);
            } else {
                circuit.push_back(node);
                currPath.pop_back();
            }
        }
        reverse(circuit.begin(), circuit.end());
        return circuit;
    }
};