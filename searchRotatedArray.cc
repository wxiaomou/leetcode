#include <iostream>

using namespace std;
class Solution {
public:
	int search(int A[], int n, int target) {
		int i = 0;
    	if (target < A[0]) {
			i = n - 1;
			while (A[i - 1] < A[i] && i > 0) {
				if (A[i] == target)
					return i;
                i--;
			}
			// special case for only rotate one. 
            if (A[i] == target) {
    			return i;
			}
		} else {
			i = 0;
			while (A[i] < A[i + 1] && i < n - 1) {
				if (A[i] == target)
					return i;
                i++;
			}
			// special case for rotate n - 1 elements.
			if (A[i] == target) {
				return i;
			}
		}
			return -1;
	}
};

int main(int argc, char **argv) {
	return 0;
}
