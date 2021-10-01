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
    int sum;
    bool hasLeftLeaf(TreeNode *r) {
        if(!r->left&&!r->right) return true;
        return false;
    }
    void sumOfLeftLeaf(TreeNode *root) {
        if(!root) return;
        if(root->left&&hasLeftLeaf(root->left)) {
            sum+=root->left->val;
            // cout<<"here for"<<root->left->val;
            sumOfLeftLeaf(root->right);
        } else {
            sumOfLeftLeaf(root->left);
            sumOfLeftLeaf(root->right);
        }
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root || !root->left&&!root->right) return 0;
        sum=0;
        sumOfLeftLeaf(root);
        return sum;
    }
};
