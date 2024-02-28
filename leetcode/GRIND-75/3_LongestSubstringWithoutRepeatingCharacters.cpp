class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        int start = 0;
        int j=1, res =1;
        while(j < n){
            int i = start;
            int flg = 0;
            for(i; i<j; i++){
                if(s[i] == s[j]){
                    flg =1;
                    break;
                }
            }
            if(flg == 1){
                start = i + 1;
                j++;
            }
            else{
                res = max(res, j - start + 1);
                j++;
            }
        }
        return res;
    }
};