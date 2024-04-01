class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int profit = 0;
        int base_index = 0;
        
        for(int i = 1; i < size; i++)
        {
            if(prices[i] - prices[base_index] > profit)
            {
                profit = prices[i] - prices[base_index];
            }
            else if(prices[i] < prices[base_index])
            {
                base_index = i;
            }
        }

        return profit;
    }
};