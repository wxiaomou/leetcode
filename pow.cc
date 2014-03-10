#include <iostream>

using namespace std;

class Solution {
public:
	double pow(double x, int n) {
	    if (!n)
    		return 1.0;
		 
		double ret = 1.0;
		bool neg = false;
		if (n < 0) {
			n = -n;
			neg = true;
		}
		if (n % 2) {
			double tmp = pow(x, n >> 1);
			ret =  x * tmp * tmp;
		} else {
			double tmp = pow(x, n >> 1);
			ret = tmp * tmp;
		}

		if (neg) 
			return 1.0 / ret;
		return ret;
	}
};
