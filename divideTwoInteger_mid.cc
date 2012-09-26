#include<iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
    	unsigned int u_dividend = 0;
			unsigned int u_divisor = 0;
			if(dividend < 0)
				u_dividend = (unsigned int)(dividend ^ -1) + 1;
			else 
				u_dividend = dividend;

			if (divisor < 0)
				u_divisor = (unsigned int)(divisor ^ -1) + 1;
			else 
				u_divisor = divisor;
			int ret = m_divide(u_dividend, u_divisor);
			
			bool d1 = dividend < 0;
			bool d2 = divisor < 0;
			if (d1 ^ d2)
				ret = (ret ^ -1) + 1;
		
			return ret;
		}

		unsigned int m_divide(unsigned int dividend, unsigned int divisor) {
			if (divisor == 0)
				return 0;
			if (dividend < divisor)
				return 0;
			if (dividend == divisor)
				return 1;
			int ret = 0;
			int count = 0;
			int tmp = divisor;
			if ((tmp << 1) > tmp) {
				while (dividend > tmp) {
						if ((tmp << 1) > tmp) {
							tmp <<= 1;
							count++;
						}	else
							break;
				}
				tmp >>= 1;
				count--;
				ret = m_divide(dividend - tmp, divisor) + (1 << count);
				} else {
				 ret = m_divide(dividend - tmp, divisor) + 1;
				}
				return ret;
			}
};
int main(int argc, char** argv) {
	Solution sol;
	cout << sol.divide(5, 2) << endl;
}
