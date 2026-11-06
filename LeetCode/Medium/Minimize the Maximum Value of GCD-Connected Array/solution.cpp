class Solution {
public:
    int minFactor(int num) {
        for(int i = 2; i <= sqrt(num); i++){
            if(num % i == 0) return i;
        }

        return -1;
    }

    long long minimumMaxValue(long long n, long long index, long long value) {
        if (value == 1) return -1;

        long long factor = minFactor(value);
        if(factor == -1){
            if(index != 0) return -1;
            factor = value;
        }

        if(factor == 2){
            long long leastValue = value - (2 * index);
            if(leastValue < 2) return -1;

            if(index == n - 1) return value; 

            long long maxValue = value + 2 * (n - index - 1);
            return maxValue;
        }

        long long leftValue = value - factor;
        long long rightValue = value + factor;

        long long leastValue = leftValue - (2 * (index - 1));  
        if(leastValue < 2) return -1;

        if(index == n - 1) return value;  

        long long maxValue = rightValue + (2 * (n - index - 2));

        return maxValue;
    }
};