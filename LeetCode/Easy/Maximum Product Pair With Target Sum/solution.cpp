class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        int n = nums.size();
        long long maxValue = INT_MIN;
        vector<int> ans = {-1,-1};
        int left = 0, right = n - 1;

        for(int left = 0; left < n; left++){
            for(int right = left + 1; right < n; right++){
                if((nums[left] + nums[right] == target) && nums[left] != nums[right] && (nums[left] * nums[right] > maxValue)){
                    if(nums[left] > nums[right]) ans = {left, right};
                    else ans = {right, left};
                    
                    maxValue = nums[left] * nums[right];
                }               
            }
        }

        return ans;
    }
};