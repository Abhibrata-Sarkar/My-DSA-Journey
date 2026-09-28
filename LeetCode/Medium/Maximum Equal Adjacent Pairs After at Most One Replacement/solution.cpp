class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        map<pair<int,int>,int> mpp;
        int pairCount = 0, maxLen = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]) pairCount++;
            else{
                int u = min(nums[i], nums[i - 1]);
                int v = max(nums[i], nums[i - 1]);

                mpp[{u,v}]++;
                maxLen = max(maxLen, mpp[{u,v}]);
            }
        }

        return pairCount + maxLen;
    }
};