class Solution {
public:
    int minChanges(string s) {
        int n = s.size();
        int cnt = 0, minCnt = INT_MAX;

        for(int i = 0; i < n - 1; i+=2){
            if(s[i] != s[i + 1]) cnt++;
        }

        minCnt = min(minCnt, cnt);

        cnt = 0;
        for(int i = 1; i < n; i+=2){
            if(s[i - 1] != s[i]){
                cnt++;
                s[i] = s[i - 1];
            }
        }

        minCnt = min(minCnt, cnt);
        return cnt;
    }
};