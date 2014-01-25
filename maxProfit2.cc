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
    //--------------------------------------------------------//
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int i = 1;
        int ret = 0;
        while (i < n) {
            int start = i - 1;
            while (i < n && prices[i] > prices[i - 1]) {
                i++;
            }
            if (i > start + 1) {
                ret += prices[i - 1] - prices[start];
            } else {
                i++;
            }
        }
        return ret;
    }
};