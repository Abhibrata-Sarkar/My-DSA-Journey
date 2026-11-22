class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        bool foundB = 0;

        for(int i = 0; i < n; i++){
            if(s[i] == 'b') foundB = 1;

            if(foundB == 1 && s[i] == 'a') return false;
        }

        return true;
    }
};