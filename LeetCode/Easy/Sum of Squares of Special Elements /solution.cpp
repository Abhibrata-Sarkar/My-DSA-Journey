class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        long long totalVal = 0;

        for(int i = 0; i < n; i++){
            if(n % (i + 1) == 0) totalVal += (long long)(nums[i] * nums[i]);
        }

        return totalVal;
    }
};