class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int median = nums[nums.size() / 2];
        int total = 0;

        for(int i = 0; i < n; i++){
            total += abs(nums[i] - median);
        }

        return total;
    }
};