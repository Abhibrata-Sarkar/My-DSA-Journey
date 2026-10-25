class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 1 || grid[i][j] == -1) return;

        grid[i][j] = -1;
        dfs(grid, i + 1, j);
        dfs(grid, i - 1 , j);
        dfs(grid, i , j + 1);
        dfs(grid, i , j - 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0) dfs(grid, i, 0);
            if(grid[i][n - 1] == 0) dfs(grid, i, n - 1);
        }
        for(int i = 0; i < n; i++){
            if(grid[0][i] == 0) dfs(grid, 0, i);
            if(grid[m - 1][i] == 0) dfs(grid, m - 1, i);
        }
        
        int cnt = 0;
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(grid[i][j] == 0){
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }

        return cnt;
    }
};