class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //count and map to check if there is already a anagram
        int count = 1;
        map <string, int> m;
        
        vector<vector<string>> answer;
        
        for (string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            if (m[temp]) {
                answer[m[temp]-1].push_back(s);
            }
            else {
                m[temp] = count++;
                answer.push_back({s});
            }            
        } 
        
        return answer;
    }
};
