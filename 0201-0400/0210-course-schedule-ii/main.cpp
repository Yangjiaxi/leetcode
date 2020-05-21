class Solution {
  public:
    vector<int> findOrder(int n, vector<vector<int>> &pre) {
        vector<int> res;
        vector<vector<int>> adj(n, vector<int>());
        vector<int> inDeg(n, 0);

        for (auto e : pre) {
            int to = e[0], from = e[1];
            adj[from].push_back(to);
            ++inDeg[to];
        }

        queue<int> Q;

        for (int i = 0; i < n; ++i)
            if (!inDeg[i]) {
                Q.push(i);
                res.push_back(i);
            }

        int topo_vis = 0;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            ++topo_vis;
            for (int v : adj[u]) {
                --inDeg[v];
                if (!inDeg[v]) {
                    Q.push(v);
                    res.push_back(v);
                }
            }
        }
        if (topo_vis == n)
            return res;
        else
            return vector<int>();
    }
};