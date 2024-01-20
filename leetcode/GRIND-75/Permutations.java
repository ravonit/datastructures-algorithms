class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(nums, result, new ArrayList<>());
        return result;
    }

    private void backtrack(int[] nums, List<List<Integer>> result, List<Integer> tempList){
        if(nums.length == tempList.size()){
            result.add(new ArrayList<>(tempList));
        }
        for(int i=0; i<nums.length; i++){
            if(tempList.contains(nums[i]))
                continue;
            tempList.add(nums[i]);
            backtrack(nums, result, tempList);
            tempList.remove(tempList.size()-1);
        }

    }
}