class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        vector<int> ind(n);
        unordered_map<int,vector<int>> pos;

        for(int i = 0; i < n; i++){
            ind[i] = pos[nums[i]].size();
            pos[nums[i]].push_back(i); 
        }

        int res = 0;

        for(int i = 0; i < n; i++){
            unordered_set<int> seen;
            int L = i;
            int R = n;

            for(int j = i; j < R; j++){
                int a = nums[j];
                if(seen.find(a) != seen.end()) continue;
                seen.insert(a);
                
                int k = seen.size();
                if(ind[j] + k - 1 >= pos[a].size()) break;

                int L2 = pos[a][ind[j] + k - 1];
                int R2 = n;
                if(ind[j] + k < pos[a].size()) R2 = pos[a][ind[j] + k];

                L = max(L,L2);
                R = min(R, R2);
                if(L > R) break;

                int end_idx = i + (k * (k + 1) / 2) - 1;
                if(L <= end_idx && end_idx < R) res++;
            }
        }

        return res;
    }
};