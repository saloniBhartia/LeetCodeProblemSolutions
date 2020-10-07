class Solution {
public:
    bool isValidBST_util(TreeNode* root, TreeNode *min, TreeNode *max){
        if(root == NULL)
            return true;
        
        if(min !=NULL and root->val <= min->val)
            return false;
        
        if(max !=NULL and root->val >= max->val)
            return false;
 
        return isValidBST_util(root->left, min, root) && isValidBST_util(root->right, root, max);
        
            
        
    }
    bool isValidBST(TreeNode* root) {
        
        return isValidBST_util(root, NULL, NULL);
    }
};
