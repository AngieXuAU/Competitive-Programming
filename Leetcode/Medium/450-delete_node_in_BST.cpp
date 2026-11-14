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
    // left branch onto right branch
    TreeNode *reattach(TreeNode *root, TreeNode *branch) {
        if (root == nullptr) {
            return branch;
        }
        root->left = reattach(root->left, branch);
        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == key) {
            TreeNode *right_child = root->right;
            if (right_child == nullptr) {
                TreeNode *left_child = root->left;
                delete (root);
                return left_child;
            }
            if (root->left == nullptr) {
                delete (root);
                return right_child;
            }
            reattach(root->right, root->left);
            delete (root);
            return right_child;
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }

        return root;
    }
};