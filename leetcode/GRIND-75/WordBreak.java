//Problem link- https://leetcode.com/problems/word-break/ 

class Solution {
    private Boolean[] t;
    private boolean checkSubStr(int idx, String substr, List<String> wordDict, int n){
        if(idx == n){
            return true;
        }
        if(t[idx] != null){
            return t[idx];
        }
        for(int l =idx+1; l<=n; l++){
            String temp = substr.substring(idx, l);
            if(wordDict.contains(temp) && checkSubStr(l, substr, wordDict, n)){
                return t[idx] = true;
            }
        }
        return t[idx] = false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        t = new Boolean[n];
        return checkSubStr(0, s, wordDict, n);
        
    }
}