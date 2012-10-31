#include <iostream>

using namespace std;
class Solution {
public:
	int sqrt(int x) {
		 if (x <= 1)
    		return x;

		int low, up;
		low = 0;
		up = x;
		int mid; 
		int last;
		while (low < up) {
			mid = (up + low) / 2;
			if (mid > 46340) {
				up = mid;
				continue;
			}
			if (mid * mid == x)
				return mid;
			if (mid * mid > x) {
				up = mid;
			} else { 
				low = mid + 1;
				last = mid;
			}
		}
		return last;
	}
};

int main(int argc,char **argv) {
	return 0;
}
