#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M;
	cin >> N >> M;

	vector<vector<int>> arr(N + 1, vector<int>(N + 1));
	vector<vector<int>> sum(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			sum[i][j] = sum[i][j - 1] + arr[i][j];
		}
	}
	
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int answer = 0;
		for (int j = x1; j <= x2; j++) {
			answer += sum[j][y2] - sum[j][y1 - 1];
		}
		cout << answer << "\n";
	}

	return 0;
}