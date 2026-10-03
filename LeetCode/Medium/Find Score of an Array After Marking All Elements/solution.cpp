class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        map<int,set<int>> mpp;

        for(int i = 0; i < n; i++){
            mpp[nums[i]].insert(i);
        }

        long long sum = 0;
        while(!mpp.empty()){
            int idx = *(mpp.begin() -> second.begin());
            mpp[nums[idx]].erase(idx);

            if(mpp[nums[idx]].empty()) mpp.erase(nums[idx]);

            sum += nums[idx];

            if(idx - 1 >= 0){
                int lidx = idx - 1;
                if(mpp.find(nums[lidx]) != mpp.end() && mpp[nums[lidx]].find(lidx) != mpp[nums[lidx]].end()){
                    mpp[nums[lidx]].erase(lidx);
                    if(mpp[nums[lidx]].empty()) mpp.erase(nums[lidx]);
                }
            }

            if(idx + 1 < n){
                int ridx = idx + 1;
                if(mpp.find(nums[ridx]) != mpp.end() && mpp[nums[ridx]].find(ridx) != mpp[nums[ridx]].end()){
                    mpp[nums[ridx]].erase(ridx);                
                    if(mpp[nums[ridx]].empty()) mpp.erase(nums[ridx]);
                }
            }
        }

        return sum;
    }
};