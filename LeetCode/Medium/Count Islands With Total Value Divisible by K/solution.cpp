class Solution {
public:
    void dfs(vector<vector<int>>& grid,int i,int j, long long& sum){
        if(i<0 || i>grid.size()-1 || j<0 || j>grid[0].size()-1 || grid[i][j] == 0 || grid[i][j] == -1)
        return;
        
        sum += grid[i][j];
        grid[i][j] = -1;
        dfs(grid,i+1,j,sum);
        dfs(grid,i-1,j,sum);
        dfs(grid,i,j+1,sum);
        dfs(grid,i,j-1,sum);  
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        long long num = 0;
        long long sum = 0;    
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] > 0){
                    dfs(grid,i,j,sum);
                    if(sum % k == 0)
                    {
                        num += 1;
                    }
                    sum = 0;
                }
            }
        }
        return num; 
    }
};