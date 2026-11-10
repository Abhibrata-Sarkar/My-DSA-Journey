class Solution {
public:
    int minCost(vector<int>& costs, int idx, vector<int>& dp){
        if(idx == 0) return 0;
        if(idx < 0) return INT_MAX;
        if(dp[idx] != -1) return dp[idx];

        int cost1 = minCost(costs, idx - 1, dp);
        if(cost1 != INT_MAX) cost1 = cost1 + (1 * 1) + costs[idx - 1];

        int cost2 = minCost(costs, idx - 2, dp);
        if(cost2 != INT_MAX) cost2 = cost2 + (2 * 2) + costs[idx - 1];

        int cost3 = minCost(costs, idx - 3, dp);
        if(cost3 != INT_MAX) cost3 = cost3 + (3 * 3) + costs[idx - 1];

        return dp[idx] = min(cost1,min(cost2,cost3));
    }
    
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, -1);
        
        return minCost(costs, n, dp);
    }
};