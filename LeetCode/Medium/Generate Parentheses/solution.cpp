class Solution {
public:
    void recursion(int n, int open, int close, string parentheses, vector<string> &res) {
        if(open == n && close == n) {
            res.push_back(parentheses);
            return;
        }
        if(open < n)
            recursion(n, open+1, close, parentheses+'(', res);
        if(close < open)
            recursion(n, open, close+1, parentheses+')', res);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        recursion(n, 0, 0, "", res);
        return res;
    }
};
