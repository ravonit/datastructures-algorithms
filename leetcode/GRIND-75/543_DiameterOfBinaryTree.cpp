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
    int getHeight(TreeNode* root) {
        if(root == NULL)
            return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int lh =0, rh = 0, ldiameter = 0, rdiameter=0;
        if(root->left){
            lh = getHeight(root->left);
            ldiameter = diameterOfBinaryTree(root->left);
        }
        if(root->right){
            rh = getHeight(root->right);
            rdiameter = diameterOfBinaryTree(root->right);
        }
        return max(lh+rh, max(ldiameter, rdiameter));
        
    }
};