#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> res;
		int l_num = L[0].length();
		if(!S.size() || S.length() < L.size() * l_num)
			return res;
		map<string, int> l;
		map<string, int> s;
		for (int i = 0; i < L.size(); i++) l[L[i]]++;
		int count = 0;
		for(int i = 0; i <= S.length() - l_num * L.size(); i++) {
			count = 0;
			s.clear();
			for (int j = 0; j < L.size(); j++) {
				string str = S.substr(i + l_num * j, l_num);
				if (l.find(str) == l.end())
					break;
				else 
					s[str]++;

				if (s[str] > l[str])
					break;

				count++;
				if (count == L.size()) {
					res.push_back(i);
				}
			}
		}
		return res;
	}
};


int main(int argc, char **argv) {
	return 0;
}
