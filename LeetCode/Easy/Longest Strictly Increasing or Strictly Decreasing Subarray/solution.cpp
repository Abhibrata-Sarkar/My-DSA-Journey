class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt = 1, maxCnt = 1;
        int flip = -1;

        for(int i = 0; i < n - 1; i++){
            if(flip == -1){
                if(nums[i] == nums[i + 1]) cnt = 1;
                else if(nums[i] > nums[i + 1]){
                    flip = 1;
                    cnt++;
                }
                else{
                    flip = 0;
                    cnt++;                    
                }
            }
            else if(flip == 1){
                if(nums[i] > nums[i + 1]) cnt++;
                else if(nums[i] == nums[i + 1]){
                    cnt = 1;
                    flip = -1;
                }
                else{
                    flip = 0;
                    cnt = 2;
                }
            }
            else{
                if(nums[i] < nums[i + 1]) cnt++;
                else if(nums[i] == nums[i + 1]){
                    cnt = 1;
                    flip = -1;
                }
                else{
                    flip = 1;
                    cnt = 2;
                }            
            }

            maxCnt = max(maxCnt, cnt);
        }    

        return maxCnt;
    }
};