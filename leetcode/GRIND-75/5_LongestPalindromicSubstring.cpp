class Solution {
public:
    int findPalindromeUtil(string s, int l, int r){
        if(l >=0 && r < s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        if(s.length() == 1)
            return s;
        int maxLen = 0;
        int start = 0;
        for(int i=0; i<s.length(); i++){
            int oldLen = findPalindromeUtil(s, i, i);
            int evenLen = findPalindromeUtil(s, i, i+1);
            int len = max(oldLen, evenLen);
            if(len > maxLen){
                start = i - (len-1)/2;
                maxLen = len;
            }
        }
        return s.substr(start, maxLen);
    }
};