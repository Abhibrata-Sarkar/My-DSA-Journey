class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] == ')') return false;

        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(m + n, false)));
        queue<pair<int,pair<int,int>>> q;
        dp[0][0][1] = true;
        q.push({1,{0,0}});

        while(!q.empty()){
            int cost = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            if((row == m - 1 && col == n - 1) && cost == 0) return true;

            int bfsRow[] = {1, 0};
            int bfsCol[] = {0, 1};

            for(int i = 0; i < 2; i++){
                int nr = row + bfsRow[i];
                int nc = col + bfsCol[i];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n){
                    int ncost = cost;
                    if(grid[nr][nc] == '(') ncost++;
                    else ncost--;

                    if(ncost < 0 || dp[nr][nc][ncost] == true) continue;

                    dp[nr][nc][ncost] = true;
                    q.push({ncost,{nr,nc}});
                }
            }
        }

        return false;
    }
};