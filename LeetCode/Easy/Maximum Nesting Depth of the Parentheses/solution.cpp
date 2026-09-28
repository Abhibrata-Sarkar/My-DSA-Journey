class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int maxi = 0;
        if(s.size() == 0) return maxi;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push('(');
            else if(s[i] == ')') st.pop();
            int n = st.size();
            maxi = max(maxi, n);
        }

        return maxi;
    }
};