class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (prices.size() <= 1) return 0;
        vector<int> ref1(1, 0);
        ref1[0] = 0;
        int _min = prices[0];
        int _max = prices[prices.size() - 1];
        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            _min = min(prices[i], _min);
            ref1.push_back(max(prices[i] - _min, ref1[i - 1]));
        }
        ret = ref1[ref1.size() - 1];
        for (int j = prices.size() - 2; j >= 0; j--) {
            _max = max(_max, prices[j]);
            int tmp = _max - prices[j] + ref1[j];
            if (tmp > ret)
                ret = tmp;
        }
        
        return ret;
    }
};