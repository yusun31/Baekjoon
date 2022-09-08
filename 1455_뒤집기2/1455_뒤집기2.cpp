#include <iostream>
using namespace std;

int arr[100][100] = { 0 };

void change(int n, int m) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = 1;
			}
		}
	}
}

int main()
{
	int N, M;
	int result = 0;

	cin >> N >> M;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = M - 1; j >= 0; j--) {
			if (arr[i][j] == 1) {
				result++;
				change(i, j);
			}
		}
	}

	cout << result << endl;

	return 0;
}