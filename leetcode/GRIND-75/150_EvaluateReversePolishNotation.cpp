class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        //int n = tokens.size();
        for(string &temp: tokens){
            if(temp != "+" && temp != "-" && temp != "*" && temp != "/"){
                st.push(stoi(temp));
            }
            else{
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                int n3;
                if(temp == "+"){
                    n3 = n1 + n2;
                }
                if(temp == "-"){
                    n3 = n2 - n1;
                }
                if(temp == "*"){
                    n3 = n2 * n1;
                }
                if(temp == "/"){
                    n3 = n2 / n1;
                }
                st.push(n3);
            }
        }
        return st.top();
    }
};