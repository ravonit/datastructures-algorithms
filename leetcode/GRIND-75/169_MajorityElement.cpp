class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int element = nums[0];
        int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == element){
                count++;
            }
            if(nums[i] != element){
                count--;
            }
            if(count == 0){
                element = nums[i];
                count = 1;
            }
        }
        return element;
    }
};