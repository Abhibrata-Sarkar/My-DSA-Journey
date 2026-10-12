class Solution {
public:
    void sieveOfErasthoses(vector<bool>& sieve) {
        int n = sieve.size() - 1;

        for(int i = 2; i * i <= n; i++){
            if(sieve[i]){
                for(int j = i * i; j <= n; j += i){
                    sieve[j] = false;    
                }
            }
        }
    }

    vector<int> maxPrimes(int n, int s) {
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;
        sieveOfErasthoses(sieve);

        vector<int> ans;
        long long sum = 0;
        for(int i = 2; i <= n; i++){
            if(sieve[i]){
                if(sum + i > s) break;
                
                sum += i;
                ans.push_back(i);
            }
        }

        return ans;
    }
};