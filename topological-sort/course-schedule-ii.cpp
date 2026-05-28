class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            for (int next : graph[curr]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (result.size() != numCourses) {
            return {};
        } else {
            return result;
        }
    }
};