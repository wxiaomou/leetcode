#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
	public:
		int largestRectangleArea(vector<int> &height) {
       		int n = height.size();
       		if (!n) return 0;
       		int _max = 0;
       		stack<int> s;
       		int area[n];
       		for (int i = 0; i < n; ++i) area[i] = 0; // count the longest width for each height
       		for (int i = 0; i < n; ++i) {
           		int t = -1;
           		while (!s.empty() && height[s.top()] >= height[i]) s.pop(); //find all the height continus on the left, !!!attention need to be >= here
           		if (!s.empty())
               		t = s.top(); // if empty the all prevois larger than current height
           		area[i] = i - t - 1; // exclude itself
           		s.push(i);
       		}
       		while (!s.empty()) s.pop();
       		for (int i = n - 1; i >= 0; --i) {
           		int t = n;
           		while (!s.empty() && height[s.top()] >= height[i]) s.pop(); //find all the height continus on the right
           		if (!s.empty())
               		t = s.top();
           		area[i] += t - i - 1; // add the right part exclude it self
           		s.push(i);
      		}
       
       for (int i = 0; i < n; ++i) {
           _max = max( _max, height[i] * (area[i] + 1) ); // add it self back
       }
       
       return _max; 
    }
		    
};

int main() {
	return 0;
}
