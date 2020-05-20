class Solution {
public:
    int max = 0;
    void f (bool hasStock, vector<int>& prices, int day, int profit, int size) {
        if (day >= size) {
            if (profit > max) max = profit;
            return;
        }
        
        int tempProfit = profit;
        
        //first try doing transaction
        if (hasStock and (day == size-1 or prices[day+1] < prices[day])) {         //trying to sell
           	f(false, prices, day+1, profit+prices[day], size);
        }
        else if (!hasStock and day != size-1 and prices[day] < prices[day+1]) {    //trying to buy
            f(true, prices, day+1, profit-prices[day], size);
        }
        
        else {
        //then try not doing the transaction
        	f(hasStock, prices, day+1, profit, size);
        }
    }
    
    int maxProfit(vector<int>& prices) {
        f(false, prices, 0, 0, prices.size());
        return max;
    }
};
