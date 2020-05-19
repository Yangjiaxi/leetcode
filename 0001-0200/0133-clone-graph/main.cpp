/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  private:
    array<Node *, 101> bucket;
    array<bool, 101> vis;

  public:
    Node *cloneGraph(Node *node) {
        if (!node)
            return nullptr;

        return one(node);
    }

    Node *one(Node *cur) {
        int v = cur->val;
        if (bucket[v])
            return bucket[v];

        Node *tmp = new Node(v);
        bucket[v] = tmp;

        for (auto nbs : cur->neighbors) {
            int v = nbs->val;
            tmp->neighbors.push_back(one(nbs));
        }

        return tmp;
    }
};