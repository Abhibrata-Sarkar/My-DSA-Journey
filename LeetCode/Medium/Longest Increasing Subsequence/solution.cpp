class Solution {
public:
    int lengthOfLIS(vector<int>& nums, vector<vector<int>>& dp, int currIdx, int prevIdx) {
        if(currIdx == nums.size()) return 0;
        if(dp[currIdx][prevIdx + 1] != -1) return dp[currIdx][prevIdx + 1];

        int notTake = lengthOfLIS(nums, dp, currIdx + 1, prevIdx);
        int take = 0;
        if(prevIdx == -1 || nums[currIdx] > nums[prevIdx]) take = 1 + lengthOfLIS(nums, dp, currIdx + 1, currIdx);

        return dp[currIdx][prevIdx + 1] = max(take, notTake); 
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxLen = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }

            if(dp[i] > maxLen) maxLen = dp[i];
        }

        for(int i = 0; i < n; i++){
            cout << dp[i] << " ";
        }

        return maxLen;
    }
};