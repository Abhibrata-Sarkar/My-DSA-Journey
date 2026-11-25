class Solution {
public:
    int longestSubstring(string s, int k, int start, int end) {
        if(end - start < k) return 0;

        vector<int> count(26, 0);
        for(int i = start; i < end; i++){
            count[s[i] - 'a']++;
        }

        for(int i = start; i < end; i++){
            if(count[s[i] - 'a'] < k){
                int left = longestSubstring(s, k, start, i);
                int right = longestSubstring(s, k, i + 1, end);

                return max(left,right);
            }
        }

        return end - start;
    }

    int longestSubstring(string s, int k) {
        int n = s.size();
        return longestSubstring(s, k, 0, n);
    }
};