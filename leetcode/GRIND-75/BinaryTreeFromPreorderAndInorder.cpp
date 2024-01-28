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
    TreeNode* buildTreeUtil(vector<int>& preorder, int left, int right,
    int rootIndex, unordered_map<int, int> mp){
        if(left >right){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[rootIndex]);
        int mid = mp[preorder[rootIndex]];
        if(left < mid){
            root->left = buildTreeUtil(preorder, left, mid-1, rootIndex+1, mp);
        }
        if(right > mid){
            root->right = buildTreeUtil(preorder, mid+1, right, rootIndex + mid - left + 1, mp);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        return buildTreeUtil(preorder, 0, n-1, 0, mp);
        
    }
};