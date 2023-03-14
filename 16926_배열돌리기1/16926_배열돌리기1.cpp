#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, M, R;
	cin >> N >> M >> R;

	vector<vector<int>> arr(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int T = min(N, M);
	T /= 2;

	int st = 0, end = 0;
	int row = N, col = M;

	while (T--) {
		queue<int> q;
		for (int i = st; i < col; i++) {
			q.push(arr[st][i]);
		}
		for (int i = end + 1; i < row; i++) {
			q.push(arr[i][col - 1]);
		}
		for (int i = col - 2; i >= st; i--) {
			q.push(arr[row - 1][i]);
		}
		for (int i = row - 2; i > end; i--) {
			q.push(arr[i][end]);
		}

		for (int i = 0; i < R; i++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}

		for (int i = st; i < col; i++) {
			arr[st][i] = q.front();
			q.pop();
		}
		for (int i = end + 1; i < row; i++) {
			arr[i][col - 1] = q.front();
			q.pop();
		}
		for (int i = col - 2; i >= st; i--) {
			arr[row - 1][i] = q.front();
			q.pop();
		}
		for (int i = row - 2; i > end; i--) {
			arr[i][end] = q.front();
			q.pop();
		}
		st++;
		end++;
		row--;
		col--;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}