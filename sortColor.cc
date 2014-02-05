#include <iostream>

using namespace std;
class Solution {
public:
	 void sortColors(int A[], int n) {
        int i = -1;
        int j = n;
        for (int k = 0; k < j; k++) {
            if (A[k] == 0) {
                if (i == k) continue;
                i++;
                swap(A[i], A[k]);
                k--;
            } else if (A[k] == 2) {
                j--;
                swap(A[k], A[j]);
                k--;
            } 
        }
    }
    
    //----------------------------------------//
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
