/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        dfs(root, val, depth, 1);
        return root;
    }

    void dfs(TreeNode* node, int val, int depth, int currDepth) {
        if(!node) return;

        if(currDepth == depth - 1) {
            TreeNode* leftChild = node->left;
            TreeNode* rightChild = node->right;

            node->left = new TreeNode(val);
            node->right = new TreeNode(val);

            node->left->left = leftChild;
            node->right->right = rightChild;
            return;
        }
        dfs(node->left, val, depth, currDepth + 1);
        dfs(node->right, val, depth, currDepth + 1);
    }
};