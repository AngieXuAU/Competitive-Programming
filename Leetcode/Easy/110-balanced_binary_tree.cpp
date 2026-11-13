#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int height(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int left_height = height(root->left);
        int right_height = height(root->right);
        if (left_height == -1 || right_height == -1 ||
            abs(height(root->left) - height(root->right)) > 1) {
            return -1;
        }
        return max(left_height, right_height) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        return (height(root) != -1);
        // return (isBalanced(root->left) && isBalanced(root->right));
    }
};