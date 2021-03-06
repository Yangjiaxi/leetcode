#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(TreeNode *root, const function<void(TreeNode *)> &helper) {
    /**
     * Morris 中序遍历
     *   1. 非递归实现
     *   2. 常数的临时空间
     */
    if (root == nullptr)
        return;

    TreeNode *current, *rightmost;

    current = root;
    while (current != nullptr) {
        if (current->left == nullptr) {
            /**
             * 没有左孩子，直接输出当前的值并前往右子树
             */
            helper(current);
            current = current->right;
        } else {
            /**
             * 有左子树，开始寻找左子树中最右边的节点
             */
            rightmost = current->left;
            while (rightmost->right != nullptr && rightmost->right != current) {
                rightmost = rightmost->right;
            }

            /**
             * 此时rightmost存储的便是current的左子树中，rightmost的节点
             */

            if (rightmost->right == nullptr) {
                /**
                 * rightmost的节点的右孩子为空，
                 * 说明这是第一次访问这个节点，
                 * 建立回跳连接，返回current
                 * >>>这个临时链接会在下个else删除<<<
                 */
                rightmost->right = current;
                current = current->left;
            } else {
                /**
                 * 明明是rightmost的节点却有右孩子，
                 * 说明这是第二次访问这个rightmost的节点，
                 * 这意味着进行到了中序遍历中的根节点阶段（{左}-[根]-{右}），
                 * 断开之前建立的临时连接，输出（子）树根，然后跳入右子树
                 */
                rightmost->right = nullptr; // 恢复原有状态
                helper(current);
                current = current->right;
            }
        }
    }
}

TreeNode *makeNode(int val) { return new TreeNode(val); }

int main() {
    auto root = makeNode(1);
    root->left = makeNode(2);
    root->right = makeNode(3);
    root->left->left = makeNode(4);
    root->left->right = makeNode(5);
    auto travel = [](TreeNode *node) { cout << node->val << " "; };
    inorder(root, travel);
    return 0;
}