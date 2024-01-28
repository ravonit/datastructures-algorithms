/*https://leetcode.com/problems/subsets/description/*/

class Solution {
public:
    void getSubsets(vector<int>&nums, vector<vector<int>> &res, int idx, vector<int> subset){
        if(idx > nums.size())
            return;
        res.push_back(subset);
        for(int i = idx; i<nums.size(); i++){
            vector<int> p = subset;
            p.push_back(nums[i]);
            getSubsets(nums, res, i+1, p);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        res.push_back(temp);
        for(int i=0; i<n; i++){
            vector<int> subset;
            subset.push_back(nums[i]);
            getSubsets(nums, res, i+1, subset);

        }
        return res;
    }
};