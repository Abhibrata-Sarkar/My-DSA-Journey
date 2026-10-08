class Solution {
public:
    string removeOuterParentheses(string s) {
        string str;
        int n = s.size();
        stack<char> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                if(!st.empty()){
                    str.push_back('(');
                }
                st.push(s[i]);
            }
            else{
                st.pop();
                if(!st.empty()){
                    str.push_back(')');
                }
            }
        }

        return str;
    }
};