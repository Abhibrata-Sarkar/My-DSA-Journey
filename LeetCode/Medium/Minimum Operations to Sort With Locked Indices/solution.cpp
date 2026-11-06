class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;

        for(int i = 0; i < n; i++){
            mpp[nums[i]] = i;
        }

        int op = 0;

        for(int i = 0; i < n; i++){
            if(mpp[nums[i]] == i + 1) continue;
            int idx = mpp[i + 1];

            for(int j = idx; j > i; j--){
                if(locked[j]){
                    locked[j] = 0;
                    k--;
                    op++;
                }

                if(locked[j - 1]){
                    locked[j - 1] = 0;
                    k--;
                    op++;
                }

                if(k < 0) return -1;

                int a = nums[j];
                int b = nums[j - 1];

                swap(nums[j], nums[j - 1]);
                mpp[nums[j]] = j;
                mpp[nums[j - 1]] = j - 1;
                op++;
            }
        }

        return op;
    }
};