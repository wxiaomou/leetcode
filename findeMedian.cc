#include <iostream>

using namespace std;

int partitions(int *A, int const low, int const high) {
		if (low == high)
			return low;

		int i = low;
		int j = high - 1;
		int x = A[high];
		
		int store_index = i - 1;

		for (;i < high - 1; ++i) {
			if (A[i] < x) {
				store_index++;
				swap(A[store_index], A[i]);
			}

		}

		swap(A[store_index + 1], A[high]);

		return store_index + 1;

}

void swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = x;
}

int select(int *A, int len, int k) {
	int left = 0;
	int right = len - 1;
	while(true) {
		//for (int a = 0; a < len; ++a) cout << A[a] << " ";
		//cout << endl;
		int loc = partitions(A, left, right);
		// cout << "loc " << loc << endl; 
		int len = loc - left + 1;
		if (len == k)
			return A[loc];

		if (loc > k)
			right = loc;
		else {
			k = k - len;
			left = loc + 1;
		}

	}
}

int main(int argc, char **argv) {
	int A[] = {4, 5, 6, 1, 2, 7, 3};
	cout << select(A, 7, 3) << endl;
}
