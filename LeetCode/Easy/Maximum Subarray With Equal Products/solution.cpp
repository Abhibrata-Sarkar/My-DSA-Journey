class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int left = 0;
        int maxSize = 2;

        for(int i = 0; i < n; i++){
            int num = nums[i];
            for(int j = 2; j * j <= num; j++){
                if(num % j == 0){
                    while(st.find(j) != st.end()){
                        int num2 = nums[left];
                        for(int k = 2; k * k <= num2; k++){
                            if(num2 % k == 0){
                                st.erase(k);
                                while(num2 % k == 0) num2 /= k;
                            }
                        }
                        st.erase(num2);
                        left++;
                    }
                    st.insert(j);
                    while(num % j == 0) num /= j;
                }
            }
            if(num > 1){
                while(st.find(num) != st.end()){
                    int num2 = nums[left];
                    for(int k = 2; k * k <= num2; k++){
                        if(num2 % k == 0){
                            st.erase(k);
                            while(num2 % k == 0) num2 /= k;
                        }
                    }
                    if(num2 > 1) st.erase(num2);
                    left++;
                }
                st.insert(num);
            }

            maxSize = max(maxSize, i - left + 1);
        }

        return maxSize;
    }
};