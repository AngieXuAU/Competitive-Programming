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
  private:
    int max_diameter = 0;

  public:
    int depth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int left_depth = depth(root->left);
        int right_depth = depth(root->right);

        max_diameter = max(max_diameter, left_depth + right_depth);
        return max(left_depth, right_depth) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root) {
        max_diameter = 0;
        depth(root);
        return max_diameter;
    }
};