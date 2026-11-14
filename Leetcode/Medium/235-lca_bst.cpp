#include <algorithm>
#include <iostream>
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
    static TreeNode *findLCA(TreeNode *root, const int &lo, const int &hi) {
        int v = root->val;

        if (lo <= v && v <= hi) {
            return root;
        } else if (lo > v) {
            return findLCA(root->right, lo, hi);
        } else {
            return findLCA(root->left, lo, hi);
        }
    }

    static TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p,
                                          TreeNode *q) {
        int lo = p->val;
        int hi = q->val;
        std::cout << "lo: " << lo << "\thi: " << hi << "\n";
        if (hi < lo) {
            std::swap(lo, hi);
        }

        return findLCA(root, lo, hi);
    }
};

int main() {
    TreeNode leaf = TreeNode(2);
    TreeNode grandchild4 = TreeNode(9);
    TreeNode grandchild3 = TreeNode(7);
    TreeNode grandchild2 = TreeNode(4);
    TreeNode grandchild1 = TreeNode(1, &leaf, nullptr);
    TreeNode child1 = TreeNode(3, &grandchild1, &grandchild2);
    TreeNode child2 = TreeNode(8, &grandchild3, &grandchild4);
    TreeNode root = TreeNode(5, &child1, &child2);

    TreeNode *sol =
        Solution::lowestCommonAncestor(&root, &child1, &grandchild2);
    std::cout << sol->val;
    return 0;
}