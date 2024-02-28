class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        vector<int> lprod(n, 1);
        vector<int> rprod(n, 1);
        lprod[0] = nums[0];
        rprod[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            lprod[i] = lprod[i-1] * nums[i];
        }
        for(int j=n-2; j>=0; j--){
            rprod[j] = rprod[j+1] * nums[j];
        }
        result[0] = rprod[1];
        result[n-1] = lprod[n-2];
        for(int i=1; i<n-1; i++){
            result[i] = lprod[i-1] * rprod[i+1];
        }
        return result; 
    }
};