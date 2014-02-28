#include <iostream>

using namespace std;
class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                if (candies[i] == 1 || candies[i] <= candies[i + 1] + 1)
                    candies[i] = candies[i + 1] + 1;
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) ret += candies[i];
        return ret;
    }
    //-----------------------------------//
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

    //----------------------------------------------//
     int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> ref(n, 1);
        int i = 0;
        while (i < n) {
            int add = 1;
            while (i + 1 < n && ratings[i + 1] > ratings[i]) {
               ref[i + 1] += add;
               add++;
               i++;
            }
            i++;
        }
        
        i = n - 1;
        while (i >= 0) {
            int add = 1;
             while (i - 1  >= 0 && ratings[i - 1] > ratings[i]) {
              if (ref[i - 1]  == 1) {
                ref[i - 1] += add;
                add++;
              } else if (ref[i - 1] < add + 1) {
                  ref[i - 1] = 1 + add;
              }
              i--;
            }
            i--;
        }
        int ret = 0;
        for (i = 0; i < n; ++i) ret += ref[i];
        return ret;
     }
};
