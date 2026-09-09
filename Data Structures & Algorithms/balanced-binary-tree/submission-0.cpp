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
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }


private:
    int dfsHeight(TreeNode* node){
        if (node == nullptr) return 0;

        int leftH = dfsHeight(node->left);
        int rightH  = dfsHeight(node ->right);

        if (leftH == -1 || rightH ==-1) return -1;
        if (abs(leftH-rightH)>1) return -1;
        return 1 + max(leftH , rightH);
    }


};
