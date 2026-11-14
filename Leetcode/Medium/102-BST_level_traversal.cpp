#include <queue>
#include <vector>

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
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> toVisit;
        vector<vector<int>> traversal;

        if (root == nullptr) {
            return vector<vector<int>>{};
        }

        toVisit.emplace(root);
        while (!toVisit.empty()) {
            int levelSize = toVisit.size();
            vector<int> result;

            for (int i = 0; i < levelSize; i++) {
                TreeNode *tmp = toVisit.front();
                toVisit.pop();
                result.push_back(tmp->val);

                // push children
                if (tmp->left != nullptr) {
                    toVisit.emplace(tmp->left);
                }
                if (tmp->right != nullptr) {
                    toVisit.emplace(tmp->right);
                }
            }
            traversal.push_back(result);
        }

        return traversal;
    }
};
