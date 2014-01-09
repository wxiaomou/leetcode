http://fisherlei.blogspot.com/2013/04/leetcode-permutation-sequence-solution.html

    /*string getPermutation(int n, int k) {
        string ret = "";
        for (int i = 1; i <= n; i++){ ret += ('0' + i); }
        
        for (int i = 1; i < k; i++) {
            for (int j = 1; j < n; j++) {
                if (ret[j] > ret[j - 1]) {
                    char tmp = ret[j];
                    ret[j] = ret[j - 1];
                    ret[j - 1] = tmp;
                    sort(ret.begin() + j, ret.end());
                    break;
                }
            }
        }
        return ret;
    }*/

    // we have n! permutation total, except first digit we have (n - 1)! permutation, so for except digit i we have (n - i - 1)! permutation.
    // for chosen = k / per_cnt; per_cnt is the permutation from digit i + i to n - 1; and digits i will increase if k is larger than (n - i - 1)!
    // then remove the chosen num, decrease k by k % per_cnt; like recursion.    
    string getPermutation(int n, int k) {
        vector<int> num;
        int per_cnt = 1;
        for (int i = 1; i <= n; ++i) {
            num.push_back(i);
            per_cnt *= i;
        }
        k--;// make zero start
        string ret;
        for (int i = 0; i < n; ++i) {
            per_cnt /= (n - i); 
            int chosen = k / per_cnt;
            ret.push_back('0' + num[chosen]);
            num.erase(num.begin() + chosen);
            k %= per_cnt;     
        }
        return ret;
    }