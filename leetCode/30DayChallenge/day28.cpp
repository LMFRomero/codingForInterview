class FirstUnique {
private:
    unordered_map <int, int> m;
    vector <int> v;
    pair<int, int> fst;
    
    void set_fst () {
        int size = v.size();
        
        for (int i = fst.second+1; i < size; i++) {
            if (m[v[i]] == 1) {
                fst = {v[i], i};
                return;
            }
        }
        
        fst = {-1, size-1};
    }
    
public:
    FirstUnique(vector<int>& nums) {
        for (int n : nums)
            m[n]++;
        
        fst = {-1, -1};
        v = nums;
        set_fst();
    }
    
    int showFirstUnique() {
        return fst.first;
    }
    
    void add(int value) {
        m[value]++;
        v.push_back(value);
        
        if (value == fst.first or fst.first == -1)
            set_fst();
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
