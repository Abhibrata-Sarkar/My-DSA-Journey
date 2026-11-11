class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        if(n == 1) return 1;
        if(n == 2) return 3;

        long long left = 0, total = 0;

        for(int i = 0; i < n; i++){
            if(i >= 2 && s[i - 2] == 'a' && s[i - 1] == 'b' && s[i] == 'c') left = i - 1;

            total += i - left + 1;
        }

        return total;
    }
};