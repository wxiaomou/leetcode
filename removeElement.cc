#include <iostream>

using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		 if (!n)
    		return 0;

		int i = 0;
		int j = 0;

		while(j < n) {
			if (A[j] != elem) {
				A[i] = A[j];
				i++;
				j++;
			} else {
				j++;
			}
		}
        if (!i)
            return i;
        else 
 		    return i;
	}
};

int main (int argc, char **argv) {
	return 0;
}
