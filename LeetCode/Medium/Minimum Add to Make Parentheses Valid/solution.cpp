class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int needed = 0;
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '(') cnt++;
            else{
                cnt--;
                if(cnt < 0){
                    needed++;
                    cnt = 0;
                }
            }
        }

        return cnt + needed;
    }
};