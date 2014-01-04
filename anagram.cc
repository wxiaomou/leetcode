#include<iostream>
#include<map>
#include<string>
			}
#include<algorithm>
using namespace std;
class Solution {
public:
	 vector<string> anagrams(vector<string> &strs) {
        int n = strs.size();
        vector<string> _strs = strs;
        if (!n) return vector<string>();
        bool first = true;
        for (auto i = 0; i < n; ++i) sort(_strs[i].begin(), _strs[i].end());
        unordered_map<string, int> hash;
        vector<string> ret;
        for (auto i = 0; i < n; ++i) {
            if (hash.count(_strs[i]) > 0) {
                if (first) {
                    ret.push_back( strs[hash[_strs[i]]] );
                    first = false;
                }
                ret.push_back(strs[i]);
            } else {
                hash[_strs[i]] = i;
            }
        }
        return ret;
    }
	//------------------------------------------//
    vector<string> anagrams(vector<string> &strs) {
         map<string, pair<string, bool> >  hash;
    		vector<string> res;
			int i = 0;
			while (i != strs.size()) {
				string tmp = strs[i];
				sort(tmp.begin(),tmp.end());
				if (hash.find(tmp) != hash.end()) {
						map<string, pair<string, bool> >::iterator it = hash.find(tmp);
						if (!it->second.second) {
							res.push_back(it->second.first);
						
    		                it->second.second = true;			
						}
						res.push_back(strs[i]);
				} else {
					pair<string, bool> p(strs[i], false);
                    hash.insert(pair<string, pair<string, bool> >(tmp, p));
				}
                ++i;
			}
			return res;
		}
};
