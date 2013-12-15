#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
  		/*int len = height.size();
			int cur = height[0];
			if (len < 2)
				return 0;
			if (len == 2)
				return height[0] <  height[1] ? height[0] : height[1];
			int max = 0;
			for (int j = 0; j < len; ++j) {
				for (int i = j + 1; i < len; ++i) {
					int hi = height[j] <  height[i] ? height[j] : height[i];
					if ((i - j)* hi > max)
						max = (i - j) * hi;
				}
			}
			 old solution using recursion;
				height.erase(height.begin());
				int tmp = maxArea(height);
			return max;
		} Brute force solution*/
	    int j = height.size() - 1;
    	int i = 0;
		int m_min = min(height[i], height[j]);
		int max = m_min * (j - i);

		while (i < j) {
			m_min = min(height[i], height[j]);

			int cap = m_min * (j - i);
			max = cap > max ? cap : max;

			if (height[i] < height[j]) {
					
					int cur = height[i];
                    i++;
					while (height[i] < cur) ++i; // in height[i] < cur then the cap will decrease, but if it larger than cur then the cap may increase
			} else {
				
					int cur = height[j];
                    j--;
					while (height[j] < cur) j--;
			}
		}
		return max;
	}
};

int main(int argc, char** argv) {
	int a[] = {1, 2, 3};
	vector<int> input(a, a + 3);
	Solution sol;
	cout << sol.maxArea(input) << endl;
	return 1;
}
