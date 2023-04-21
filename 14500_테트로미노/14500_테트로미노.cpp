#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;

	cin >> N >> M;

	vector<vector<int>> arr(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int tmp[5] = { 0 };
	int cnt[5] = { 0 };
	for (int k = 0; k < 5; k++) {
		switch (cnt[k])
		{
		case 0:
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (i + 1 < N && j + 1 < M) {
						tmp[k] = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
					}
					if (tmp[k] > cnt[0]) cnt[0] = tmp[k];
				}
			}
		case 1:
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (i + 2 < N && j + 1 < M) {
						tmp[k] = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
					}
					if (tmp[k] > cnt[1]) cnt[1] = tmp[k];
					if (i + 1 < N && j + 2 < M) {
						tmp[k] = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
					}
					if (tmp[k] > cnt[1]) cnt[1] = tmp[k];
					if (j - 1 >= 0 && i + 2 < N) {
						tmp[k] = arr[i][j] + arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 2][j - 1];
					}
					if (tmp[k] > cnt[1]) cnt[1] = tmp[k];
					if (j - 1 >= 0 && i + 1 < N && j + 1 < M) {
						tmp[k] = arr[i][j] + arr[i][j + 1] + arr[i + 1][j - 1] + arr[i + 1][j];
					}
					if (tmp[k] > cnt[1]) cnt[1] = tmp[k];
				}
			}
		case 2:
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (i + 2 < N && j + 1 < M) {
						tmp[k] = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
					}
					if (tmp[k] > cnt[2]) cnt[2] = tmp[k];
					if (j - 1 >= 0 && i + 2 < N) {
						tmp[k] = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j - 1];
					}
					if (tmp[k] > cnt[2]) cnt[2] = tmp[k];
					if (j + 1 < M && i + 2 < N) {
						tmp[k] = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j];
					}
					if (tmp[k] > cnt[2]) cnt[2] = tmp[k];
					if (j - 1 >= 0 && i + 2 < N) {
						tmp[k] = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j - 1];
					}
					if (tmp[k] > cnt[2]) cnt[2] = tmp[k];
					if (j + 2 < M && i + 1 < N) {
						tmp[k] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
					}
					if (tmp[k] > cnt[2]) cnt[2] = tmp[k];
					if (j + 2 < M && i + 1 < N) {
						tmp[k] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j];
					}
					if (tmp[k] > cnt[2]) cnt[2] = tmp[k];
					if (j + 2 < M && i + 1 < N) {
						tmp[k] = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
					}
					if (tmp[k] > cnt[2]) cnt[2] = tmp[k];
					if (i - 1 >= 0 && j + 2 < M) {
						tmp[k] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2];
					}
					if (tmp[k] > cnt[2]) cnt[2] = tmp[k];
				}
			}
		case 3:
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (i + 3 < N) {
						tmp[k] = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
					}
					if (tmp[k] > cnt[3]) cnt[3] = tmp[k];
					if (j + 3 < M) {
						tmp[k] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
					}
					if (tmp[k] > cnt[3]) cnt[3] = tmp[k];
				}
			}
		case 4:
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (i - 1 >= 0 && j + 2 < M) {
						tmp[k] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1];
					}
					if (tmp[k] > cnt[4]) cnt[4] = tmp[k];
					if (i + 1 < N && j + 2 < M) {
						tmp[k] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
					}
					if (tmp[k] > cnt[4]) cnt[4] = tmp[k];
					if (j + 1 < M && i + 2 < N) {
						tmp[k] = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
					}
					if (tmp[k] > cnt[4]) cnt[4] = tmp[k];
					if (j - 1 >= 0 && i + 2 < N) {
						tmp[k] = arr[i][j] + arr[i + 1][j - 1] + arr[i + 1][j] + arr[i + 2][j];
					}
					if (tmp[k] > cnt[4]) cnt[4] = tmp[k];
				}
			}
		default:
			break;
		}
	}

	int count = 0;
	for (int i = 0; i < 5; i++) {
		if (cnt[i] > count) count = cnt[i];
	}

	cout << count << endl;

	return 0;
}