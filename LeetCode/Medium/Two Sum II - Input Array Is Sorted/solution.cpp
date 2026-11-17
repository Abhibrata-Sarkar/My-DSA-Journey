class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int> ans;
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while(low <= high)
        {
            if(arr[low] + arr[high] == target)
            {
                ans.push_back(low+1);
                ans.push_back(high+1);
                return ans;
            }
            else if(arr[low] + arr[high] > target)
            {
                high = high - 1;
            }
            else
            {
                low = low + 1;
            }
        }
        ans.push_back(low+1);
        ans.push_back(high+1);
        return ans;
    }
};