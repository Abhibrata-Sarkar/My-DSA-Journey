class Solution {
public:
    int MOD = 1e9 + 7;
    int recursion(vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int row, int col, int prev) {
        if(row >= grid.size() || col >= grid[0].size()) return 0;
        if(row == grid.size() - 1 && col == grid[0].size() - 1) return 1;

        if(dp[row][col][prev + 1] != -1) return dp[row][col][prev + 1];

        int right = 0, down = 0;
        if(grid[row][col] == 1){
            if(prev == 0) down = recursion(grid, dp, row + 1, col, 1);
            else right = recursion(grid, dp, row, col + 1, 0);
        }
        else{
            down = recursion(grid, dp, row + 1, col, 1);
            right = recursion(grid, dp, row, col + 1, 0);
        }

        return dp[row][col][prev + 1] = (right + down) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1)));

        return recursion(grid, dp, 0, 0, -1);
    }
};