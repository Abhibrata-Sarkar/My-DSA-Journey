class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int maxSize = 1;
        int left = 0;
        int cnt = 0;
        int cntRow = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] % k != 0){
                mpp[(nums[i] % k)]++;
                cntRow = 0;
            }
            else{
                cnt++;
                cntRow++;
            }

            maxSize = max(maxSize, cntRow);

            int size = i - left + 1; 
            if(mpp.size() == 1 && cnt == 0){
                long long req = mpp.begin() -> first;
                if(((size - 1) * req) % k == 0) maxSize = max(maxSize, size);
            }
            else{
                if(mpp.size() > 1|| (mpp.size() == 1 && cnt > 0)){
                    while(left < i && (mpp.size() > 1 || (mpp.size() == 1 && cnt > 0))){
                        if(nums[left] % k == 0) cnt--;
                        else{
                            mpp[nums[left] % k]--;
                            if(mpp[nums[left] % k] == 0) mpp.erase(nums[left] % k);                        
                        }
    
                        left++;
                    }                    
                }
            }
        }

        return maxSize;
    }
};