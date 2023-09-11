//Problem Link:- 
/*https://leetcode.com/problems/valid-palindrome/description*/


class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                s[i] = s[i] + 32;
            }
        }
        int low = 0;
        int high = n-1;
        while(low <= high){
            if(!isalnum(s[low])){
                low++;
                continue;
            }
            if(!isalnum(s[high])){
                high--;
                continue;
            }
            if(s[low] != s[high])
                return false;
            else{
                low++;
                high--;
            }
        }
        return true;
    }
};