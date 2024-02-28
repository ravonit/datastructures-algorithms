class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int mid  = 0;
        int r = n-1;
        while(mid <= r){
            if(nums[mid] == 0){
                swap(nums[l], nums[mid]);
                l++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else if(nums[mid] == 2){
                swap(nums[r], nums[mid]);
                r--;
            }
        }
    }
};