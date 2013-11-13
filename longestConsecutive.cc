class Solution {
public:
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
};