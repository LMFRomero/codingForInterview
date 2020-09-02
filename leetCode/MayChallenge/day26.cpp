class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map <int, int> prefix;
        int counter = 0;
        int ans = 0;
        int n = nums.size();
        
        prefix[0] = -1;
        
        for (int i = 0; i < n; i++) {
            counter += nums[i] ? -1 : 1;
            if (prefix.find(counter) == prefix.end())
                prefix[counter] =  i;
            else {
                ans = max(ans, i-prefix[counter]);
            }
            cout << counter << " ";
        }
        cout << endl;
        
        return ans;
    }
};
