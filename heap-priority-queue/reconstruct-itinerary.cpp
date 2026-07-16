class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, set<string>> adjList;
        for (auto& v : tickets) {
            adjList[v[0]].insert(v[1]);
        }
        vector<string> result;
        string currAirport = "JFK";
        while (true) {
            result.push_back(currAirport);
            set<string>* st = &adjList[currAirport];
            if (st->empty()) break;
            currAirport = *st->begin();
            st->erase(st->begin());
        }
        return result;
    }
};