class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> sortedStones;
        int first, second;
        
        
        for (int i : stones) sortedStones.push(i);
        
        while (sortedStones.empty() == false) {
            first = sortedStones.top();
            sortedStones.pop();
            if (sortedStones.empty()) return first;
            
            second = sortedStones.top();
            sortedStones.pop();
            
            if (first-second > 0) sortedStones.push(first-second); 
        }
        
        return 0;
    }
};
