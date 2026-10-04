class Solution {
public:
    int minRotations(string s) {
        int total = 0;
        int currNum = 0;
        for(int i = 0; i < 10; i++){
            int currVal = s[i] - '0';
            if(currNum == currVal) continue;

            int front = 0, back = 0;
            if(currVal > currNum) front = currVal - currNum;
            else front = (10 - currNum) + currVal;

            if(currVal < currNum) back = currNum - currVal;
            else back = currNum + (10 - currVal);

            total += min(front, back);
            currNum = currVal;  
        }

        return total;
    }
};