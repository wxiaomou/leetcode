#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if (!n) return 0;
        int i = 0, j = 0;
        while (j < n) {
            if (A[j] == elem) {
                j++;
                continue;
            }
            A[i++] = A[j++];
        }
        return i;
    }
    //-----------------------------------//
	int removeElement(int A[], int n, int elem) {
        if (!n) return 0;
        int i = 0;
        int j = 0;
        bool start = false;
        while (j < n) {
            while (A[j] == elem && j < n) j++;
            if (j < n) {
                A[i++] = A[j++];
                start = true;
            }
                
        }
        return i;
    }
    //--------------------------------//
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
