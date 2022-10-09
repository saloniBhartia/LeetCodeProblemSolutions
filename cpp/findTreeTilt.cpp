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
    int findSum(TreeNode *a) {
        if(!a) return 0;
        return a->val+findSum(a->left)+findSum(a->right);
    }
public:
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        if(!root->left&&!root->right) return 0;
        if(!root->left) {
            return abs(findSum(root->right))+ findTilt(root->right);
        }
        if(!root->right) {
            return abs(findSum(root->left)) + findTilt(root->left);
        }
        
        return abs(findSum(root->left)-findSum(root->right)) + findTilt(root->left) + findTilt(root->right);
    }
};
