#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;
//log(m + n) solution refer to http://www2.myoops.org/course_material/mit/NR/rdonlyres/Electrical-Engineering-and-Computer-Science/6-046JFall-2005/30C68118-E436-4FE3-8C79-6BAFBB07D935/0/ps9sol.pdf
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {fi
        if ((m + n) % 2) {
            if (!m)
                return B[n / 2];
            else if (!n)
                return A[m / 2];
                
            return med(A, m, B, n, (m + n) / 2 + 1, 1, m);
        } else {
            if (!m)
                return (B[n / 2 - 1] + B[n / 2]) / 2.0;
            else if (!n)
                return (A[m / 2 - 1] + A[m / 2]) / 2.0;
                
            return (med(A, m, B, n, (m + n) / 2, 1, m) + med(A, m, B, n, (m + n) / 2 + 1, 1, m)) / 2.0;
        }
    }
    
    int med(int A[], int m, int B[], int n, int k, int left, int right) {
        //!!!k, left, right here are not the index, the start from 1.
        if (left > right)
            return med(B, n, A, m, k, 1, n); // median not in A
            
        int i = (left + right) / 2 - 1; 
        int mid = i + 1; // there are mid - 1 elements less than A[i]
        int j = k - mid; // j elements in B which should less than A[i]
        
        //special case
        if (j > n) { 
            return med(A, m, B, n, k, mid + 1, right); //A[i] < median, B is not enough need to get more elements in A
        } else if (j < 0) {
            return med(A, m, B, n, k, left, mid - 1); // A[i] > median
        }
        
        //special case
        if ((j == 0 && A[i] <= B[j]) || (j == n && A[i] >= B[j - 1])) {
            return A[i];
        } else if (j == 0 && A[i] > B[j]) { // A[i] > median
            return med(A, m, B, n, k, left, mid - 1);
        } else if ((j == n && A[i] < B[j - 1])) {
            return med(A, m, B, n, k, mid + 1, right);
        }
        
        if (j > 0 && j < n) {
            if (A[i] >= B[j - 1] && A[i] <= B[j]) // in B excact j elements less than A[i], so A[i] is the roght one.
                return A[i];
            else if (A[i] < B[j - 1]) { // A[i] < median
                return med(A, m, B, n, k, mid + 1, right);
            } else {
                return med(A, m, B, n, k, left, mid - 1);
            }
        }
    }
};
/* second time did 
double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if ( (m + n) % 2 ) {
            if (!m)
                return B[n / 2];
            else if (!n) 
                return A[m / 2];
            return find(A, m, B, n, 1, m, (m + n) / 2 + 1);
        } else {
               if (!m)
                return (B[n / 2 - 1] + B[n / 2]) / 2.0;
            else if (!n) 
                return (A[m / 2 - 1] + A[m / 2]) / 2.0;
            return (find(A, m, B, n, 1, m, (m + n) / 2) + find(A, m, B, n, 1, m, (m + n) / 2 + 1)) / 2.0;
        }
    }
    
    double find(int A[], int m, int B[], int n, int left, int right, int k) {
        if (left > right)
            return find(B, n, A, m, 1, n, k);
        
        int mid = (left + right) / 2;
        int i = mid - 1;
        int j = k - mid;
        
        if (j < 0) return find(A, m, B, n, left, mid - 1, k);
        if (j > n) return find(A, m, B, n, mid + 1, right, k);
        
        if ((j == 0 && B[j] >= A[i]) || (j == n && B[n - 1] <= A[i])) return A[i];
        
        if (j == 0) return find(A, m, B, n, left, mid - 1, k);
        if (j == n) return find(A, m, B, n, mid + 1, right, k);
        
        if (A[i] >= B[j - 1] && A[i] <= B[j]) {
            return A[i];
        } else if (A[i] < B[j - 1]) {
            return find(A, m, B, n, mid + 1, right, k);
        } else {
            return find(A, m, B, n, left, mid - 1, k);
        }
    }
*/
    
/*class Solution {
    public:
            double findMedianSortedArrays(int A[], int m, int B[], int n) {
                if (!m) {
                    return ((n % 2) ?  (B[n / 2]) : (double) (B[n / 2 - 1] + B[n / 2]) / 2.0);
                } else if (!n) {
                    return ((m % 2) ?  (A[m / 2]) : (double) (A[m / 2 - 1] + A[m / 2]) / 2.0);
                } else {
                    return rec(m, A, n, B);
                }
            }

            double base (int med1, int C[], int n) {
                if (n == 1) 
                    return (med1 + C[0]) / 2.0;

                if (n % 2 == 0) {
                    int a = C[n / 2 - 1], b = C[n / 2];
                    if (med1 > b)
                        return b;
                    else if (med1 < a)
                        return a;
                    else 
                        return med1;
                } else {
                    int a = C[n / 2 - 1], b = C[n / 2], c = C[n / 2 + 1];
                    if (med1 > c)
                        return (b + c) / 2.0;
                    else if (med1 > b)
                        return (med1 + b) / 2.0;
                    else 
                        return (b + max(med1, a)) / 2.0;
                }
            }

            double base2 (int med1, int med2, int C[], int n) {
              if (n % 2 == 0) {
                  int a = ((n / 2 - 2) >= 0) ? C[n / 2 - 2] : INT_MIN; 
                  int b = C[n / 2 - 1], c = C[n / 2];
                  int d = ((n / 2 + 1) < n) ? C[n / 2 + 1] : INT_MAX;

                   if (med2 <= b)
                        return (max(a, med2) + b) / 2.0;
                    else if (med2 <= c)
                        return (max(b, med1) + med2) / 2.0;
                    else if (med1 <= d)
                        return (c + max(med1, b)) / 2.0;
                    else 
                        return (c + min(med1, d)) / 2.0;
             }  else {
                int a = C[n / 2 - 1], b = C[n / 2], c = C[n / 2 + 1];
                if (med2 <= b)
                    return max(med2, a);
                else if (med2 <= c)
                    return max(med1, b);
                else if (med1 <= c)
                    return max(med1, b);
                else 
                    return c;
             }
            }

            
            double rec(int m, int A[], int n, int B[]) {
                if (m + n < 1)
                    return 0.0;

                if (m == 1)
                    return base(A[0], B, n);
                else if (n == 1)
                    return base(B[0], A, m);
                else if (m == 2) 
                    return base2(A[0], A[1], B, n);
                else if (n == 2)
                    return base2(B[0], B[1], A, m);
                else {

                    int i = m / 2, j = n / 2, k = 0;

                    if (A[i] <= B[j]) {
                        k = (m % 2 == 0) ? min(i - 1, n - 1 - j) : min(i, n - 1 - j);
                        return rec(m - k, A + k, n - k, B);
                    } else {
                        k = (n % 2 == 0) ? min(j - 1, m - 1 - i) : min(j, m - 1 - i);
                        return rec(m - k, A, n - k, B + k);
                    }
                }

            }        
};*/

int main(int argc, char **argv) {
    return 0;
}
