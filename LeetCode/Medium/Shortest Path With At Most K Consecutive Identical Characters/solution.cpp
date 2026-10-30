class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        int m = edges.size();
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0; i < m; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            adj[u].push_back({v,w});
        }

        priority_queue<
            pair<int,pair<int,pair<int,char>>>,
            vector<pair<int,pair<int,pair<int,char>>>>,
            greater<pair<int,pair<int,pair<int,char>>>>
        > pq;
        vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
        dist[0][k - 1] = 0;
        
        pq.push({0,{0,{k - 1, labels[0]}}});

        while(!pq.empty()){
            int cost = pq.top().first;
            int node = pq.top().second.first;
            int cons = pq.top().second.second.first;
            char s = pq.top().second.second.second;
            pq.pop();

            if(cost > dist[node][cons]) continue;
            if(node == n - 1) return cost;

            for(auto it: adj[node]){
                int nnode = it.first;
                int ncost = cost + it.second;
                char t = labels[nnode];

                if(cons == 0 && s == t) continue;
                if(s == t){
                    if(dist[nnode][cons - 1] > ncost){
                        dist[nnode][cons - 1] = ncost;
                        pq.push({ncost,{nnode,{cons - 1,t}}});
                    }
                }
                else{
                    if(dist[nnode][k - 1] > ncost){
                        dist[nnode][k - 1] = ncost;
                        pq.push({ncost,{nnode,{k - 1,t}}});
                    }             
                }
            }
        }

        return -1;
    }
};