class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum % 2 != 0)
            return false;
        sum /= 2;
        int dp[sum+1];
        dp[0] = true;
        for(int i=1; i<=sum; i++){
            dp[i] = false;
        }
        
        for(int i=0; i<n; i++){
            for(int j=sum; j>0; j--){
                if(nums[i] <= j){
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
            }
        }
        return dp[sum];
             
    }
};