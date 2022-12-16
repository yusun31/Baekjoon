#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	vector<int> arr(N + 1);
	vector<int> sum(N + 1, 0);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		
		int answer = sum[y] - sum[x - 1];

		cout << answer << "\n";
	}

	return 0;
}