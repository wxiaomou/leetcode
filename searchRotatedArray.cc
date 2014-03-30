#include <iostream>

using namespace std;
class Solution {
public:
// key: use A[mid] and A[start] to find the increase part, if target inside the increase part then choose accoeding part else choose the oposite
 int search(int A[], int n, int target) {
        if (!n) return -1;
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (A[mid] == target) return mid;
            if (target == A[end]) return end;
            if (target == A[start]) return start;
            
        
            if (A[mid] < A[start]) {
                if (target > A[mid] && target < A[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                if (target > A[start] && target < A[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        
        return -1;
    }

  //------------------O(n)---------------------//
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

// binary search way O(log(n)) key:分类讨论
class Solution {
public:
    int search(int A[], int n, int target) {
        if (!n) return 0;
        int start = 0;
        int end = n - 1;
        return _search(A, start, end, target);
    }
    
    int _search(int A[], int start, int end, const int target) {
        if (start > end) return -1;
        if (start == end) {
            if (A[start] == target)
                return start;
            else
                return -1;
        }
        int mid_ind = (start + end) / 2;
        int mid = A[mid_ind];
        if (target == mid) return mid_ind;
        //find it rotated more than half
        if (mid > A[end]) {
            if (target <= A[end]) {							//important!!! need to have equal, otherwise wiil search the wrong half.
                return _search(A, mid_ind + 1, end, target);
            } else if (target > mid) {
                return _search(A, mid_ind + 1, end, target);
            } else {
                return _search(A, start, mid_ind, target);
            }
        }  else {
           if (target < mid) {
               return _search(A, start, mid_ind, target);
           } else if (target <= A[end]) { 					// same
              //return _search(A, start, mid_ind, target);
              return _search(A, mid_ind + 1, end, target);
           } else {
               //return _search(A, mid_ind + 1, end, target);
               return _search(A, start, mid_ind, target);
           }
        }
    }
};
int main(int argc, char **argv) {
	return 0;
}
