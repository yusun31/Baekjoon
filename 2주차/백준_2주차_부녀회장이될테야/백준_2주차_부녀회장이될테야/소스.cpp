#include <iostream>
using namespace std;

int main()
{
	int T;
	int k, n;
	int arr[40][40] = { 0 };

	cin >> T;

	int count = 0;
	while (count != T) {
		cin >> k >> n;

		for (int i = 1; i <= n; i++) {
			arr[0][i] = i;
		}

		for (int i = 0; i <= k; i++) {
			arr[i][1] = 1;
		}

		for (int i = 1; i <= k; i++) {
			for (int j = 2; j <= n; j++) {
				for (int l = 1; l <= j; l++) {
					arr[i][j] += arr[i - 1][l];
				}
			}
		}

		cout << arr[k][n] << endl;

		for (int i = 0; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				arr[i][j] = 0;
			}
		}

		count++;
	}

	return 0;
}