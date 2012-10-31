#include <iostream>

using namespace std;
class Solution {
public:
	void sortColors(int A[], int n) {
		if (!n)
			return;

		int l = 0;
		int i = 0;
		int r = n - 1;

		while (i <= r) {
			if (A[i] == 0) {
				swap(A[l], A[i]);
				l++;
				i++;
			} else if(A[i] == 2){
				swap(A[i], A[r]);
				r--;
			} else {
				i++;
			}
		}
		return;
	}

	void swap(int &a, int &b) {
		int tmp = a;
		a = b;
		b = tmp;
		return;
	}
};

int main(int argc, char **argv) {
	return 0;
}
