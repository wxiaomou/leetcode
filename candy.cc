#include <iostream>

using namespace std;
class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!ratings.size()) return 0;
        int ret = ratings.size();
        if (ratings.size() == 1) return 1;
        vector<int> r1 (ratings.size(), 0);
        vector<int> r2 (ratings.size(), 0);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i - 1] < ratings[i]) {
                r1[i] = r1[i - 1] + 1;
            } 
        } 
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i + 1] < ratings[i]) {
                r2[i] = r2[i + 1] + 1;
            }
        }
        
        for (int i = 0; i < ratings.size(); i++) {
            ret += max(r1[i], r2[i]);
        }
        return ret;
    }
};
