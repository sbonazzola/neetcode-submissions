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
private:
TreeNode* insertHelper(TreeNode* root, int val ){
if (root == nullptr){
    return new TreeNode(val);
}

else if (val > root->val){
    root->right = insertHelper(root->right,val);

}

else if(val < root->val){
    root->left = insertHelper(root->left,val);

}


return root;

}

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
    root = insertHelper(root,val);
    return root;
        
    }
};