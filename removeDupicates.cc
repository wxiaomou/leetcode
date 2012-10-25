#include <iostream>

using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		 if (!n)
    		return 0;

		int i = 0;
		int j = 1;
		while (j < n) {
			if (A[j - 1] != A[j]) {
				i++;

				A[i] = A[j];
                j++;
			} else 
				j++;
		}
		return ++i;
	}
};

int main (int argc, char **argv) {
	return 0;
}
