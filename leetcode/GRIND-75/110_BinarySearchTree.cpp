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
        if(root == NULL)
            return true;
        if(abs(calculateHeight(root->left) - calculateHeight(root->right)) <= 1 &&
            isBalanced(root->left) && isBalanced(root->right))
                return true;
        else
            return false;
        
    }

    int calculateHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        queue<TreeNode*> q;
        int height = 0;
        q.push(root);
        while(!q.empty()){
            height++;
            int p = q.size();
            for(int i =0; i< p; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return height;
    }
};