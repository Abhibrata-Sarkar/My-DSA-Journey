class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int score = 0, level = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == '(') level++;
            if(s[i] == ')'){
                level--;
                if(s[i - 1] == '(') score += 1 << level;
            }
        }

        return score;
    }
};