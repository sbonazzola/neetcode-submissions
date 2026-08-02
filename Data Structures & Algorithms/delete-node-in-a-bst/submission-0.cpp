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

TreeNode* removeMin(TreeNode* root){
    if (root->left == nullptr){
        TreeNode* right = root->right;
        delete root;
        return right;
    }
    root->left = removeMin(root->left);
    return root;
}

TreeNode* removeHelper(TreeNode* root, int val){
    if(root == nullptr){
        return nullptr;
    }

    else if(val < root->val){
        root->left = removeHelper(root->left,val);
    }

    else if(val> root->val){
        root->right = removeHelper(root->right,val);
    }

    else{

        if (root->left == nullptr){

            TreeNode* right = root->right;
            delete root;
            return right;
        }

        if (root->right == nullptr){
            TreeNode* left = root->left;
            delete root;
            return left;
        }

        TreeNode* successor = root->right;
        while (successor->left != nullptr) successor = successor->left;
        root->val = successor->val;
        root->right = removeMin(root->right);
    }

    return root;
}

public:
    TreeNode* deleteNode(TreeNode* root, int val) {
        root = removeHelper(root,val);
        return root;
        
    }
};