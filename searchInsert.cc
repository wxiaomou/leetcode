#include <iostream>

using namespace std;
class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		if (!n)
			return 0;

		for (int i = 0; i < n; ++i) {
			if (A[i] == target)
				return i;
			else if (A[i] > target) 
				return i;
		}
		return n;
	}
};

int main(int argc, char **argv) {
	return 0;
}
