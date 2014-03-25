class Solution {
public:
nt longestConsecutive(vector<int> &num) {
        int n = num.size();
        unordered_map<int, int> hash;
        if (!n) return 0;
        int first = 0, last = 0;
        for (int i = 0; i < n; i++) {
            if (hash.count(num[i]) > 0) continue;
            
            hash[num[i]] = num[i];
            
            int beg = num[i], end = num[i];
            if (hash.count(num[i] - 1) > 0) // because for each num not in the hash we will look for num - 1 and num + 1, so for every seq nomatter the order it may have, we can reach the begin and end, e.g. 9, 4, 3, 8, 5, 6
                beg = hash[num[i] - 1];
            if (hash.count(num[i] + 1) > 0)
                end = hash[num[i] + 1];
            
            hash[beg] = end; // because next we access the num beg, the only way is from number (num - 1), because num and num + 1 are already in the hash, and they will immediately continue; so here hash[brg] = end;
            hash[end] = beg;
            if (end - beg + 1 > last - first + 1) {
                first = beg;
                last = end;
            }
        }
        return last - first + 1;
    }
    
    //------------------------------------//

    int longestConsecutive(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        set<int> hash;
        int ret = 0;
        for (int i = 0; i < num.size(); i++) hash.insert(num[i]);
        for (int i = 0; i < num.size(); i++) {
            int len = 0;
            int tmp = num[i];
            while (hash.find(tmp) != hash.end()) {
                len++;;
                hash.erase(tmp);
                tmp++;
            }
            tmp = num[i] - 1;
            while (hash.find(tmp) != hash.end()) {
                len++;
                hash.erase(tmp);
                tmp--;
            }
            ret = max(ret, len);
        }
        return ret;
    }
    
    /*
     int longestConsecutive(vector<int> &num) {
        int ret = 0;
        if (!num.size()) return ret;
        unordered_set<int> hashset;
        for ( auto i = 0; i < num.size(); ++i ) {
            hashset.insert(num[i]);
        }
        
        for ( auto i = 0; i < num.size(); ++i ) {
            if (hashset.count(num[i]) == 0) continue;
            int tmp = 1;
            hashset.erase(num[i]);
            int j = 1;
            while (hashset.count(num[i] + j) > 0) {
                tmp++;
                hashset.erase(num[i] + j);
                j++;
            }
            
            j = 1;
            while (hashset.count(num[i] - j) > 0) {
                tmp++;
                hashset.erase(num[i] - j);
                j++;
            }
            ret = max(ret, tmp);
        }
        return ret;
    }
    */
};