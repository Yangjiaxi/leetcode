class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

        vector<bool> vis(numCourses, false);
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> inDeg(numCourses, 0);

        for (auto e : prerequisites) {
            int to = e[0], from = e[1];
            adj[from].push_back(to);
            ++inDeg[to];
        }

        queue<int> Q;
        // Enqueue all node whose in-degree is 0
        for (int i = 0; i < numCourses; ++i)
            if (!inDeg[i])
                Q.push(i);

        int topo_vis = 0;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            ++topo_vis;
            for (int v : adj[u]) {
                --inDeg[v];
                if (!inDeg[v])
                    Q.push(v);
            }
        }
        return topo_vis == numCourses;
    }
};