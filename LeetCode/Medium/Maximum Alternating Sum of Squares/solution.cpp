class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            nums[i] = nums[i] * nums[i]; 
        }

        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        int k = 0;
        long long res = 0;

        while(left <= right){
            if(k % 2 == 0){
                res += nums[right];
                right--;
            }
            else{
                res -= nums[left];
                left++;
            }
            k++;
        }

        return res;
    }
};