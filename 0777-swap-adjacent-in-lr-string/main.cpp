class Solution {
  public:
    bool canTransform(string start, string end) {
        int i, j;
        i = j = 0;
        int size = start.length();
        while (i < size && j < size) {
            while (i < size && start[i] == 'X')
                ++i;
            while (j < size && end[j] == 'X')
                ++j;
            if (i >= size || j >= size)
                break;
            if (start[i] != end[j])
                return false;
            if (start[i] == 'L' && i < j)
                return false;
            if (start[i] == 'R' && i > j)
                return false;
            ++i;
            ++j;
        }
        while (i < size && start[i] == 'X')
            ++i;
        while (j < size && end[j] == 'X')
            ++j;
        return i >= size && j >= size;
    }
};