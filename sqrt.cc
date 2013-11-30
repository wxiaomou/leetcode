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
				up = 46341; // cannot use 46340 cause we will not try high(becuase low < hign) so use 46340 will lost itself.
				continue;
			}
			if (mid * mid == x)
				return mid;
			if (mid * mid > x) {
				up = mid;
			} else { // if the number cannot not sqrt by a int, we need to return the larger one which square less than that, eg. if x = 14 return 3, so we only update last here. 
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
