class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        int n = types.size();
        vector<pair<int,pair<int,int>>> nums;

        for(int i = 0; i < n; i++){
            int type = types[i];
            int col = colors[i];

            if(nums.empty() || nums.back().first != type || nums.back().second.first != col){
                if(groupSize[type] != 1) nums.push_back({type,{col,1}});
            }
            else{
                int cnt = nums.back().second.second;
                nums.pop_back();
                cnt++;
                if(cnt != groupSize[type]) nums.push_back({type,{col,cnt}});
            }
        }

        return nums.empty();
    }
};