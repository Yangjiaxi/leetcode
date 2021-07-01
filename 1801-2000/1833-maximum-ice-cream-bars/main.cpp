class Solution {
  public:
    int maxIceCream(vector<int> &costs, int coins) {
        sort(costs.begin(), costs.end());

        int cnt = 0, bal = coins;

        for (int i = 0; i < costs.size(); ++i) {
            if (bal < costs[i])
                break;
            else {
                bal -= costs[i];
                cnt += 1;
            }
        }

        return cnt;
    }
};