#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> res;
		map<int, int> hash;
		for (int i = 0; i < numbers.size(); i++) {
			if (hash.find(target - numbers[i]) != hash.end()) {
				res.push_back(hash[target - numbers[i]]);
				res.push_back(i + 1);
				break;
			}
			hash.insert(pair<int, int> (numbers[i], i + 1));
		}
		return res;
	}
};

int main(int argc, char **argv) {
	vector<int> test;
	test.push_back(5);
	test.push_back(75);
	test.push_back(25);
	Solution sol;
	test = sol.twoSum(test, 100);
	return 0;
}
