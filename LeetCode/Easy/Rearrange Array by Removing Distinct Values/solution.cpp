class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> mpp(101, 0);

        for(int i = 0; i < n; i++) mpp[nums[i]]++;

        vector<int> ans;
        while(ans.size() != nums.size()){
            for(int i = 0; i < 101; i++){
                if(mpp[i] > 0){
                    ans.push_back(i);
                    mpp[i]--;
                }
            }
        }

        return ans;
    }
};