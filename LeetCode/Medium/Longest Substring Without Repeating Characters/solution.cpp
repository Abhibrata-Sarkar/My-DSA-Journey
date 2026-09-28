class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> character(128, 0);
        int left = 0;
        int right = 0;
        int cnt = 0;
        while(right < n){
            character[s[right]]++;
            while(character[s[right]] > 1 && left <= right){
                character[s[left]]--;
                left++;
            }
            cnt = max(cnt, right - left + 1);
            right++;   
        }

        return cnt;
    }
};