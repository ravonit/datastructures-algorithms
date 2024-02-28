class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_till_now = -INT_MAX;
        int curr_sum = 0;
        for(int i=0; i< nums.size(); i++){
            curr_sum += nums[i];
            if(curr_sum > max_till_now)
                max_till_now = curr_sum;
            if(curr_sum < 0)
                curr_sum = 0;
        }
        return max_till_now;

    }
};