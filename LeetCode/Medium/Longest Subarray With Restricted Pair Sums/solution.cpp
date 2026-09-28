class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0, left = 0;
        unordered_map<int,int> mpp;

        for(int right = 0; right < n; right++){
            mpp[nums[right]]++;

            for(int j = left; j < right; j++){
                int sum = nums[j] + nums[right];
                int diff = nums[right] - nums[j];

                while(left <= j && (mpp[sum] > 0 || (diff > 0 && (( diff != nums[j] && mpp[diff] > 0) || (diff == nums[j] && mpp[nums[j]] > 1))))){
                    mpp[nums[left]]--;
                    left++;
                }
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};