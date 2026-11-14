class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        int lastValidA = -1;
        int lastA = -1;
        long long total = 0;
        int left = 0;
        bool flagB = false;

        for(int i = 0; i < n; i++){
            if(s[i] == 'a') lastA = i;
            else if(s[i] == 'b'){
                if(lastA != -1) lastValidA = lastA;
                flagB = true;
            }
            else{
                if(flagB && lastValidA != -1){
                    left = max(left, lastValidA + 1);
                    lastValidA = -1;
                }
            }
            total += i - left + 1;
        }

        return total;
    }
};