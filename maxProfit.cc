class Solution {
    public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int ret = 0;
        int _min = prices[0];
        for (int i = 1; i < n; i++) {
            _min = min(prices[i], _min);
            ret = max(ret, prices[i] - _min);
        }
        return ret;
    }

    //----------------------------------------//
    int maxProfit(vector<int> &prices) {
        // the same Solution instance will be reused for each test case.
        if (!prices.size()) return 0;
        int _min = prices[0];
        int i = 0;
        int ret = 0;
        
        while (i < prices.size()) {
            _min = min(_min, prices[i]);
            ret = max(ret, prices[i] - _min);
            i++;
        }
        return ret;
    }

};