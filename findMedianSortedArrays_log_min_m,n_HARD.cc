#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;
class Solution {
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
            
           
};

int main(int argc, char **argv) {
    return 0;
}
