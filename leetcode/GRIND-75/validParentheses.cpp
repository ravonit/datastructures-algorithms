//Problem Link:- 
/*https://leetcode.com/problems/valid-parentheses/*/


class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char>st;
        if(n == 0)
            return true;
        for(int i=0; i< s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else if(st.empty()) // single close bracets
                return false;
            else if(s[i] == ')' && st.top() == '(' && !st.empty()){
                st.pop();
            }
            else if(s[i] == '}' && st.top() == '{' && !st.empty()){
                st.pop();
            }
            else if(s[i] == ']' && st.top() == '[' && !st.empty()){
                st.pop();
            }
            else
                return false;
        }
        return st.empty(); 
    }
};