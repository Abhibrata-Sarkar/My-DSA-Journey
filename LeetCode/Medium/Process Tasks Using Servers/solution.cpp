class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size();
        int n = tasks.size();

        using pii = pair<int, int>;
        using ppii = pair<long long, pair<int, int>>;        

        priority_queue<pii, vector<pii>, greater<pii>> freeServers;
        priority_queue<ppii, vector<ppii>, greater<ppii>> tasksDur;

        for(int i = 0; i < m; i++){
            freeServers.push({servers[i],i});
        }

        vector<int> ans;
        long long time = 0;

        for(int i = 0; i < n; i++){
            while(!tasksDur.empty() && tasksDur.top().first <= time){
                int server = tasksDur.top().second.first;
                int idx = tasksDur.top().second.second;
                tasksDur.pop();

                freeServers.push({server,idx});
            }

            if(!freeServers.empty()){
                int server = freeServers.top().first;
                int idx = freeServers.top().second;
                freeServers.pop();

                tasksDur.push({time + tasks[i],{server,idx}});
                ans.push_back(idx);                
            }
            else{
                time = tasksDur.top().first;
                int server = tasksDur.top().second.first;
                int idx = tasksDur.top().second.second;
                tasksDur.pop();

                tasksDur.push({time + tasks[i],{server,idx}});
                ans.push_back(idx);
            }

            if(time == i) time++;
        }

        return ans;
    }
};