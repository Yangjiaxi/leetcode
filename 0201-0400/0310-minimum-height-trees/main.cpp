class Solution {
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1)
            return {0};
        /*
            解最多只有两个元素
            证明：对于分叉节点，仅保留最长的分叉，这样树就会缩成一条链
            链长度为奇数：一个最优解 o-o-x-o-o   : 2
            链长度为偶数：两个最优解 o-o-x-x-o-o : 3

            IDEA:
           拓扑排序思路，一圈圈地删除外围叶子节点，最后剩下的1/2个节点就是根
        */
        vector<int> in_deg(n, 0);
        vector<vector<int>> adj(n, vector<int>());

        for (auto e : edges) {
            int a = e[0], b = e[1];
            ++in_deg[a];
            ++in_deg[b];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> res;

        for (int i = 0; i < n; ++i)
            if (in_deg[i] == 1)
                res.push_back(i);

        int left = n;
        while (left > 2) {
            vector<int> tmp;
            left -= res.size();
            for (int u : res) {
                for (int v : adj[u]) {
                    int &t = in_deg[v];
                    --t;
                    if (t == 1)
                        tmp.push_back(v);
                }
            }
            res = tmp;
        }
        return res;
    }
};