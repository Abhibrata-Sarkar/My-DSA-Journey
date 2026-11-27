class Solution {
public:
    int solve(vector<pair<int,int>>& nums, vector<vector<int>>& dp, int idx, int budget) {
        if(budget == 0) return 0;
        if(idx == nums.size()) return -1e9;
        if(dp[idx][budget] != -1) return dp[idx][budget];

        int take = -1e9, notTake = -1e9;
        if(budget >= nums[idx].first) take = nums[idx].second + solve(nums, dp, idx + 1, budget - nums[idx].first);
        notTake = solve(nums, dp, idx + 1, budget);

        return dp[idx][budget] = max(take, notTake);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<pair<int,int>> nums;

        int minVal = INT_MAX;
        for(int i = 0; i < n; i++){
            minVal = min(minVal, items[i][1]);

            int cnt = 1;
            for(int j = 0; j < n; j++){
                if(i != j && items[j][0] % items[i][0] == 0) cnt++;
            }

            nums.push_back({items[i][1],cnt});
        }

        vector<vector<int>> dp(n + 1, vector<int>(budget + 1, -1));

        int maxResult = 0;
        for(int i = 0; i <= budget; i++){
            int result = solve(nums, dp, 0, i);
            int totalResult = result + ((budget - i) / minVal);

            maxResult = max(maxResult, totalResult);
        }

        return maxResult;
    }
};