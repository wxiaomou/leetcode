#include <iostream>
using namespace std;

class Solution {
public:
	// key: use A[mid] and A[start] to find the increase part, if target inside the increase part then choose accoeding part else choose the oposite
	// if A[start] == A[mid] in which we cannot judge which side is increase part, wo juse do nothing to it, simply increase start.
	bool search(int A[], int n, int target) {
        if (!n) return -1;
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (A[mid] == target || target == A[end] || target == A[start]) return true;
            
            if (A[mid] < A[start]) {
                if (target > A[mid] && target < A[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else if (A[mid] > A[start]){
                if (target > A[start] && target < A[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                start++; // !!!!important!!!!
            }
        }
        
        return false;
    }
    
    
	//----------------------------------------//
	bool search(int A[], int n, int target) {
		int i = 0;
        if (target < A[0]) {
			i = n - 1;
			while (A[i - 1] <= A[i] && i > 0) { // duplication !!!! so we have '='
				if (A[i] == target)
					return true;
                i--;
			}
			// special case for only rotate one. 
        if (A[i] == target) {
    			return true;
			}
		} else {
			i = 0;
			while (A[i] <= A[i + 1] && i < n - 1) {
				if (A[i] == target)
                    return true;
                i++;
			}
			// special case for rotate n - 1 elements.
			if (A[i] == target) {
				return true;
			}
		}
			return false;
	}
};

int main(int argc, char **argv) {
	return 0;
}
