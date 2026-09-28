class Solution {
public:
    int checkPalindrome(string& s, int leftIdx, int rightIdx) {
        while(leftIdx >= 0 && rightIdx < s.size() && s[leftIdx] == s[rightIdx]){
            leftIdx--;
            rightIdx++;
        }

        return rightIdx - leftIdx - 1;
    }

    string longestPalindrome(string s) {
        int n = s.size();

        int start = 0;
        int end = 0;
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            int odd = checkPalindrome(s, i, i);
            int even = checkPalindrome(s, i, i + 1);
            int maxLen = max(odd,even);

            if(maxLen > end - start){
                start = i - (maxLen - 1) / 2;
                end = i + maxLen / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }
};