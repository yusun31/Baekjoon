#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
	if (n == 1 || n == 2)
		return 1;
	else
		return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
	vector<int> f(n + 1);

	int count = 0;
	f[1] = 1, f[2] = 1;
	for (int i = 3; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
		count++;
	}
	return count;
}

int main()
{
	int n;

	cin >> n;

	int re = fib(n);
	int dy = fibonacci(n);

	cout << re << " " << dy << endl;

	return 0;
}