class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int maxi = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == i) continue;

            maxi &= nums[i];
        }

        if(maxi == -1) return 0;
        return maxi;
    }
};