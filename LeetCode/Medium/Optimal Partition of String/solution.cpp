class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int cnt = 1;
        unordered_set<char> st;

        for(int i = 0; i < n; i++){
            if(st.find(s[i]) != st.end()){
                st.clear();
                cnt++;
            }

            st.insert(s[i]);
        }

        return cnt;
    }
};