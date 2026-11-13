class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long cost = 0;

        deque<pair<int,int>> dq;
        int r = n - 1;

        for(int l = n - 1; l >= 0; l--){
            int num = nums[l];
            int count = 1;

            while(!dq.empty() && dq.back().first < num){
                auto[nextNum, nextCount] = dq.back();
                dq.pop_back();
                count += nextCount;
                cost += 1LL * (num - nextNum) * nextCount;
            }
            dq.emplace_back(num, count);

            while(cost > k){
                auto [rightmostPeak, rightmostCount] = dq.front();
                dq.pop_front();
                cost -= (rightmostPeak - nums[r]);
                --r;
                if(rightmostCount > 1){
                    dq.emplace_front(rightmostPeak, rightmostCount - 1);
                }
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};