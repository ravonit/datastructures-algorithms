class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        bool flag = false;
        int result = 0;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
        }
        for(auto it = mp.begin(); it != mp.end(); ++it){
            if(it->second % 2 == 0){
                result += it->second;
            }
            else{
                flag = true;
                result = result + it->second - 1;
            }

        }
        if(flag)
            return result + 1;
        else
            return result;
    }
};