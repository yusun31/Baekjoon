#include <iostream>
using namespace std;

int main()
{
	string str;
	int N;
	int k;
	int a[10000] = { 0 };
	int n = 0;

	cin >> N;

	while (N != 0) {
		cin >> str;

		if (str == "push") {
			cin >> k;
			a[n] = k;
			n++;
		}

		if (str == "pop") {
			if (a[0] != 0) {
				cout << a[0] << endl;
				for (int i = 0; i < n; i++) {
					a[i] = a[i + 1];
				}
				a[n - 1] = 0;
				n--;
			}
			else
				cout << "-1" << endl;
		}

		if (str == "empty") {
			if (n == 0)
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}

		if (str == "front") {
			if (a[0] != 0)
				cout << a[0] << endl;
			else
				cout << "-1" << endl;
		}

		if (str == "back") {
			if (n == 0) {
				cout << "-1" << endl;
			}
			else
				cout << a[n - 1] << endl;
		}

		if (str == "size") {
			cout << n << endl;
		}

		N--;
	}

	return 0;
}