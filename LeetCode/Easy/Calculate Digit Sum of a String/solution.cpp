class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
                string next_s = "";
            for(int j = 0; j < s.size(); j += k){
                int sum = 0;

                for(int i = j; i < min((int)s.size(),j + k); i++){
                    sum += s[i] - '0'; 
                }

                next_s += to_string(sum);
            }
            s = next_s;
        }

        return s;
    }
};