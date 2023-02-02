#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = N; i > 0; i--) {
		for (int j = 0; j <= (N * 2 - 1) / 2 - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i * 2 - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= (N * 2 - 1) / 2 - i; j++) {
			cout << " ";
		}
		for (int j = 1; j <= i * 2 - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}