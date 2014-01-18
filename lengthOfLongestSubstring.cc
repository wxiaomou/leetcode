#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	/*int lengthOfLongestSubstring(string s) {
    if (!s.length())
			return 0;

		map<char, int> hash;
		hash.clear();
		int max = 0;
		
		int i = 0;
		int j = 0;

		while (i < s.length()) {
			if (hash.find(s[i]) == hash.end()) {
				hash.insert(pair<char, int> (s[i], i));
				max = (i - j + 1) > max ? (i - j + 1) : max;
		        i++;
			} else {
				//while (j <= hash[s[i]]) // wrong because hash[s[i]] will be erase at the last time 
				int index = hash[s[i]];
				while (j <= index) {
					hash.erase(s[j]);
					j++;
				}
			}
	
		}
		return max;
	}*/

	
	int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        hash.clear();
        int ret = 0;
        int tmp = 0;
        int j = 0;
        for ( auto i = 0; i < s.length(); ++i ) {
             if (hash.count(s[i]) > 0) {
                int index = hash[s[i]];
                while (j < index) {
                    hash.erase(s[j]);                  
                }
                j++;
                hash[s[i]] = i;// need to insert s[i] here, O.W. we will miss this one, just change the value to be the new i of key s[i],
                			  // don't forget increase j, j should always be the start index of current sequence!!!
                tmp = i - index;
            } else {
                hash[s[i]] = i;
                tmp++;
                ret = max(tmp, ret);
            }
        }
        return ret;
    }

	
};

int main(int argc, char **argv) {
	Solution sol;
	cout << sol.lengthOfLongestSubstring("abcbacbb") << endl;

}
