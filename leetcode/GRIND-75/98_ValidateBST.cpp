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
    bool checkBST(TreeNode* root, long minValue, long maxValue){
        if(root == NULL)
            return true;
        if(root->val <= minValue || root->val >= maxValue)
            return false;
        return checkBST(root->left, minValue, root->val) && checkBST(root->right, root->val, maxValue);
    }
    bool isValidBST(TreeNode* root) {
        long minValue = LONG_MIN;
        long maxValue = LONG_MAX;
        return checkBST(root, minValue, maxValue);
    }
};