class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj, vector<long long>& vis, vector<int>& subtree, string& colors) {
        int size = 1;
        long long childGain = 0;
        for(auto it: adj[node]){
            if(it != parent){
                size += dfs(it, node, adj, vis, subtree, colors);
                childGain += min(0LL, vis[it]);
            }
        }

        if(colors[node] == 'R') vis[node] = -size + childGain;
        else vis[node] = size + childGain;

        return subtree[node] = size;
    }
    
    long long minCost(int n, string colors, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < m; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> subtree(n, 0);
        vector<long long> vis(n, LLONG_MAX);
        dfs(0, -1, adj, vis, subtree, colors);

        long long costForBlue = 0;
        for(int i = 0; i < n; i++){
            if(colors[i] == 'R') costForBlue += subtree[i];
        }

        long long costForRed = LLONG_MAX;
        for(int i = 0; i < n; i++){
            costForRed = min(costForRed, costForBlue + vis[i]);
        }
        
        return min(costForBlue, costForRed);
    }
};