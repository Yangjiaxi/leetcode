class Solution {
  public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min(min(a, b), c);
        int z = max(max(a, b), c);
        int y = a + b + c - x - z;
        if (x + 1 == y && y + 1 == z)
            return {0, 0};
        if (y - x <= 2 || z - y <= 2)
            return {1, z - x - 2};
        return {2, z - x - 2};
    }
};