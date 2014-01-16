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
           		int t = -1; // !!!t is the rightest index which ouosidet the range in which height[i] is minimum, so if s is empty t should be -1, because 0 is valid
           		while (!s.empty() && height[s.top()] >= height[i]) s.pop(); //find all the height continus on the left, !!!attention need to be >= here
           		if (!s.empty())
               		t = s.top(); // if empty the all prevois larger than current height
           		area[i] = i - t - 1; // exclude itself
           		s.push(i);
       		}
       		while (!s.empty()) s.pop();
       		for (int i = n - 1; i >= 0; --i) {
           		int t = n; // !!!t is the leftest item which ouosidet the range in which height[i] is minimum, so t = s.top() and we don't need to + 1, becuse t is leftest outside range
           		           // need to be n!!!
                        // cause if s is not empty s.top() is the leftest out of range, so t - i we do not +1, 
                        //but if it empty we cannot use n - 1, cause we miss one there and we cannot simply change to t - i + 1, 
                        //cause this will mess up the no empty case;
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
