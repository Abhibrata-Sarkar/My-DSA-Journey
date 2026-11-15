class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int MOD = 1e9 + 7;
        int even = 1, odd = 0;
        long long ans = 0;
        int sum = 0;

        for(auto it: arr){
            sum = (sum + it) % 2;
            if(sum == 1){
                ans = (ans + even) % MOD;
                odd++;
            }
            else{
                ans = (ans + odd) % MOD;
                even++;
            }
        }

        return ans;
    }
};