#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
    public:
            vector<int> twoSum(vector<int> &numbers, int target) {
                vector<int> ret;
                multimap<int, int> hash;
                for (int i = 0; i < numbers.size(); i++)
                    hash.insert(pair<int, int>(numbers[i], i + 1));

                multimap<int, int>::iterator it = hash.begin();
                multimap<int, int>::iterator ref;
                while (it != hash.end()) {
                    if ((ref = hash.find(target - (*it).first)) != hash.end()) {
                        if ((*ref).second == (*it).second) {
                            it++;
                            continue;
                        } else {
                            int first = (*it).second > (*ref).second ? (*ref).second : (*it).second;
                            int second = (*it).second < (*ref).second ? (*ref).second : (*it).second;
                            ret.push_back(first);
                            ret.push_back(second);
                            break;
                        }
                    }
                    it++;
                }
                return ret;
            }
    //------------------------------------------------------//
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        if (n < 2) return vector<int> ();
        vector<int> ret;
        unordered_map<int, int> hash;
        for (int i = 0; i < n; i++) {
            if (hash.count(target - numbers[i]) > 0) {
                ret.push_back(hash[target - numbers[i]] + 1);
                ret.push_back(i + 1);
                return ret;
            } else {
                hash[numbers[i]] = i;
            }
        }
        return ret;
    }
           
};

int main (int argc, char **argv) {
    return 0;
}
