struct SegTree {
    int ql, qr;
    int n;
    vector<int> maxv;

    SegTree(int n) : maxv() {
        this->n = n;
        maxv.resize(n * 4);
    }

    void build(vector<int> &a, int o, int L, int R) {
        if (L == R)
            maxv[o] = a[L - 1];
        else {
            int left = o * 2;
            int right = o * 2 + 1;
            int M = L + (R - L) / 2;
            build(a, left, L, M);
            build(a, right, M + 1, R);
            maxv[o] = max(maxv[left], maxv[right]);
        }
    }

    int query(int o, int L, int R) {
        if (ql <= L && R <= qr) return maxv[o];

        int M = L + (R - L) / 2;
        int ans = -999999;
        if (ql <= M) ans = max(ans, query(o * 2, L, M));
        if (M < qr) ans = max(ans, query(o * 2 + 1, M + 1, R));

        return ans;
    }

    int get(int l, int r) {
        this->ql = l;
        this->qr = r;
        return query(1, 1, n);
    }

    void init(vector<int> &a) { build(a, 1, 1, n); }
};

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        if (n == 1) return vector<int>{nums[0]};

        auto tree = SegTree(n);

        tree.init(nums);

        int gap = k - 1;
        int ans_len = n - gap;
        vector<int> ans;
        ans.reserve(ans_len);

        for (int l = 1; l <= ans_len; ++l) {
            // int q = tree.get(l, l + gap);
            ans.push_back(tree.get(l, l + gap));
        }
        return ans;
    }
};