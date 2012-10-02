#include<iostream>

using namespace std;

int fibonacci(int n) {
	if (n < 3)
		return 1;
	int a = 1;
	int b = 1;
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		ret = a + b;
		a = b;
		b = ret;
	}

	return ret;
}


int main(int argc, char **argv) {
	int n = 5;
	cout << fibonacci(n) << endl;
	n = 10;
	cout << fibonacci(n) << endl;

	return 1;
}
