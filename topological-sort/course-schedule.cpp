class Solution {
public:
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &visited) {
        if (visited[node] == 1) {
            return false;
        }
        if (visited[node] == 2) {
            return true;
        }
        visited[node] = 1; // mark visited
        for (int adj : graph[node]) {
            if (!dfs(adj, graph, visited)) {
                return false;
            }
        }
        visited[node] = 2; // mark finished
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto &pair : prerequisites) {
            graph[pair[1]].push_back(pair[0]); // store course in index of prereq
        }
        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, graph, visited)) {
                    return false;
                }
            }
        }

        return true;
        
    }
};