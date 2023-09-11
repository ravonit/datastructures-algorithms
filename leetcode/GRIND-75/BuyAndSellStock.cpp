//Problem Link:- 
/**https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int least_price = prices[0];
        int max_price = prices[0];
        int max_profit = 0;
        for(int i=0; i<n; i++){
            max_profit = max(max_profit, (prices[i] - least_price));
            if(prices[i] < least_price)
                least_price = prices[i];
        }
        return max_profit;
    }
};