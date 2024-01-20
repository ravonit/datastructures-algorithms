//Problem Link:- 
/*https://leetcode.com/problems/combination-sum/*/

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        findCombinations(candidates, target, result, 0, new ArrayList<>());
        return result;
    }
    private void findCombinations(int[] candidates, int target, List<List<Integer>> result, int start, List<Integer> tempList){
        if(target<0)
            return;
        else if(target == 0){
            result.add(new ArrayList<>(tempList));
        }
        else{
            for(int i=start; i<candidates.length; i++){
                tempList.add(candidates[i]);
                findCombinations(candidates, target-candidates[i], result, i, tempList);
                tempList.remove(tempList.size()-1);
            }
        }
    }
}