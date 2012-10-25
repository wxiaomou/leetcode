#include <iostream>

using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (!n)
    		return 0;
		if (n == 1)
			return 1;

		int i = 0;
		int j = 1;
		int count = 0;

		while (j < n) {
			if (A[j - 1] != A[j]) {
				i++;
				A[i] = A[j];
				j++;
				count = 0;
			} else {
				if (count < 1) {
					i++;
					A[i] = A[j];
					j++;
					count++;
				} else {
                    count++;
					j++;
				}
			}
		}

		return ++i;
	}
};

int main (int argc, char **argv) {
	return 0;
}
