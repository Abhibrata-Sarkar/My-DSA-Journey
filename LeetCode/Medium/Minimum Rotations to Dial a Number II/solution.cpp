class Solution {
public:
    int func(int currNum, int nextNum) {
        int total = 0;

        int currVal = nextNum;
        if(currNum == currVal) return 0;

        int front = 0, back = 0;
        if(currVal > currNum) front = currVal - currNum;
        else front = (10 - currNum) + currVal;

        if(currVal < currNum) back = currNum - currVal;
        else back = currNum + (10 - currVal);

        total = min(front, back);

        return total;        
    }

    int minRotations(int n, string s) {
        if(n == 1) return min(s[0] - '0', 10 - (s[0] - '0'));

        vector<int> reverse(n, 0);
        vector<int> forward(n, 0);

        reverse[n - 1] = 0;
        reverse[n - 2] = reverse[n - 1] + func(s[n - 1] - '0', s[n - 2] - '0');

        for(int i = n - 3; i >= 0; i--){
            reverse[i] = reverse[i + 1] + func(s[i + 1] - '0', s[i] - '0');
        }

        forward[0] = func(0, s[0] - '0');
        forward[1] = forward[0] + func(s[0] - '0', s[1] - '0');

        for(int i = 2; i < n; i++){
            forward[i] = forward[i - 1] + func(s[i - 1] - '0', s[i] - '0');
        }

        int minVal = min(forward[n - 1], func(0, s[n - 1] - '0') + reverse[0]);
        for(int i = 1; i < n; i++){
            minVal = min(minVal, forward[i - 1] + func(s[i - 1] - '0', s[n - 1] - '0') + reverse[i]);
        }

        return minVal;
    }
};