class Solution {
    public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int i = 0;
        int ret = 0;
        while (i < prices.size() - 1) {
            if (prices[i + 1] > prices[i]) {
                ret += prices[i + 1] - prices[i];
            }
            i++;
        }
        return ret;
    }
};