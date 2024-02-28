class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> res;
        for(int i=0; i<n-1; i++){
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    res.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(sum < 0)
                    l++;
                else
                    r--;
            }
        }
        vector<vector<int>>res2(res.begin(), res.end());
        return res2;
    }
};