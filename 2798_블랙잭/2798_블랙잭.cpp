#include <iostream>
using namespace std;

int main()
{
	int N, M;
	int num[100] = { 0 };
	int value;
	int sum = 0;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				if (num[i] + num[j] + num[k] <= M) {
					value = num[i] + num[j] + num[k];
					sum = max(value, sum);
				}
			}
		}
	}

	cout << sum << endl;

	return 0;
}