class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a = 0, b = 1, c = 1;
        if(a + b + c == n) return true;
        
        while(c < n){
            int d = b + c;
            if(d + a == n) return true;
            
            a = b;
            b = c;
            c = d;
        }

        return false;
    }
};