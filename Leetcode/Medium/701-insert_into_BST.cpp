
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
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root)
            return new TreeNode(val);

        int v = root->val;
        if (val < v) {
            TreeNode *result = insertIntoBST(root->left, val);
            if (result != root) {
                root->left = result;
            }
        } else {
            TreeNode *result = insertIntoBST(root->right, val);
            if (result != root) {
                root->right = result;
            }
        }

        // idiomatically:
        // if (val < root->val) {
        //     root->left = insertIntoBST(root->left, val);
        // } else {
        //     root->right = insertIntoBST(root->right, val);
        // }

        return root;
    }
};