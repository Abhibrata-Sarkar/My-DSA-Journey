class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int n = s.size();
        int dep = 0;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                ans.push_back(dep % 2);
                dep++;
            }
            else{
                dep--;
                ans.push_back(dep % 2);
            }
        }

        return ans;
    }
};