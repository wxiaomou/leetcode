/**
 *  http://tech-queries.blogspot.com/2011/03/maximum-area-rectangle-in-histogram.html
 */
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
    	stack<int> s;
		int area[n]; // to store the longest width rectangle with height[i];
		int t;

		for (int i = 0; i < n; ++i) area[i] = 0;
		for (int i = 0; i < n; i++) {
			// find the first height that less than height[i], so that we can get the width of this rectangle
			while(!s.empty()) {
				if (height[i] <=height[s.top()]) 
					s.pop();
				else
					break;
			}

			if (s.empty())
				t = -1;
			else
				t = s.top();

			area[i] = i - t - 1;
			s.push(i);
		}

		while(!s.empty()) s.pop();

		for (int i = n - 1; i >= 0; i--) {
			// find the first height that less than height[i], so that we can get the width of this rectangle
			while(!s.empty()) {
				if (height[i] <=height[s.top()]) 
					s.pop();
				else
					break;
			}

			if (s.empty())
				t = n;   // need to be n!!!
                         // cause if s is not empty s.top() is the leftest out of range, so t - i we do not +1, but if it empty we cannot use n - 1,
                         // cause we miss one there and we cannot simply change to t - i + 1, cause this will mess up the no empty case;
			else
				t = s.top();

			area[i] += t - i - 1;
			s.push(i);
		
		}
		int max = 0;
		for (int i = 0; i < n; ++i) {
			if ((height[i] * (area[i] + 1) > max ))
				max = height[i] * (area[i] + 1);
		}

		return max;
    }
};

int main(int argc, char **argv) {
	return 0;
}
