#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.size() == 0)
			return 0;

		int n = triangle.size() - 2;
		while (n >= 0) {
			for (int i = 0; i <= n; i++) {
				triangle[n][i] += min(triangle[n + 1][i], triangle[n + 1][i + 1]);
			}
			n--;
		}
		return triangle[0][0];
	}
};

int main(int argc, char **argv) {
	return 0;
}
