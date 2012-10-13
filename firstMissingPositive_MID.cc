#include<iostream>
#include<math>
using namespace std;

class Solution {
public: 
	int firstMissingPositive(int A[], int n) {
			if (n == 0)
				return 1;
		for (int i = 0; i < n; ++i) {
				if (A[i] <= 0)
					A[i] = n + 1;
		}
		
		for (int i = 0; i < n; ++i) {
			int index = abs(A[i]);

			if (index >= 1 && index <= n && A[index - 1] > 0)// in case duplicated number, reverse even time will occur problem
				A[index - 1] = -A[index - 1]; // mark all the location that its according number has shown up in somewhere in this array.
		}

		for (int i = 0; i < n; ++i) {
			if (A[i] > 0)
				return i + 1;
		}
		return n + 1;
	}
};
int main(int argc, char** argv) {
}