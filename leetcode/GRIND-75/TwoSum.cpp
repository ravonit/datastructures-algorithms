//Problem Link:- 
/*https://leetcode.com/problems/two-sum/*/


class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n = nums.length;
        int [] result = new int[2];
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i=0; i<n; i++){
            int val = target - nums[i];
            if(mp.containsKey(val)){
                result[0] = i;
                result[1] = mp.get(val);
            }
            else{
                mp.put(nums[i], i);
            }
        }
        
        return result;
    }
}