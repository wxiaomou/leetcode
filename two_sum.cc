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
           
};

int main (int argc, char **argv) {
    return 0;
}
