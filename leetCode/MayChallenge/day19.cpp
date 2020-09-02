class StockSpanner {
    int today;
    vector<pair<int, int>> v;
    
public:
    StockSpanner() {
        v.clear();
        today = -1;
        v.emplace_back(today, INT_MAX);
    }
    
    int next(int price) {
        today++;
        
        while (!v.empty() and v.back().second <= price)
            v.pop_back();
        
        int ans = today-v.back().first;
        v.emplace_back(today, price);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
