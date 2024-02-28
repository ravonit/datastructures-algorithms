class Solution {
public:
    void getCombinationUtil(int i, string &res, vector<string> &resultList, unordered_map<char, string> &mp, string &digits){
        if(res.length() == digits.length()){
            resultList.push_back(res);
            return;
        }
        string temp = mp[digits[i]];
        for(int j=0; j<temp.length(); j++){
            res.push_back(temp[j]);
            getCombinationUtil(i+1, res, resultList, mp, digits);
            res.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> resultList;
        string res="";
        if(digits.length() == 0)
            return {};
        getCombinationUtil(0, res, resultList, mp, digits);
        return resultList;
        
    }
};