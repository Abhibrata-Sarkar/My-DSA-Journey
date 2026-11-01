class Solution {
public:
    int concatenateNum(int num1, int num2) {
        int mixedNum = 0;
        int multi = 1;

        while(num2 > 0){
            int rem = num2 % 10;
            mixedNum = (rem * multi) + mixedNum;

            multi *= 10;

            num2 /= 10; 
        }

        while(num1 > 0){
            int rem = num1 % 10;
            mixedNum = (rem * multi) + mixedNum;

            multi *= 10;
            num1 /= 10; 
        }

        return mixedNum;
    }

    int minMergedInteger(vector<int>& nums) {
        int n = nums.size();

        int minNum = INT_MAX;
        for(int i = 0; i < n; i+=2){
            int combinedNum = concatenateNum(nums[i], nums[i + 1]);
            minNum = min(minNum, combinedNum);
        }

        return minNum;
    }
};