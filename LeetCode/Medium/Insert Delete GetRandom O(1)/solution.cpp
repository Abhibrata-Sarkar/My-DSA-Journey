class RandomizedSet {
public:
    unordered_map<int,int> mpp;
    vector<int> nums;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mpp.find(val) == mpp.end()){
            nums.push_back(val);
            mpp[val] = nums.size() - 1;
            return true;
        }
        else return false;
    }
    
    bool remove(int val) {
        if(mpp.find(val) != mpp.end()){
            int lastElement = nums.back();
            int idx = mpp[val];
            nums[idx] = lastElement;
            mpp[lastElement] = idx;
            nums.pop_back();
            mpp.erase(val);

            return true;
        }
        else return false;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */