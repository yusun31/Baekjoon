#include <iostream>
using namespace std;

int N, M;
int visited[9] = { 0 };
int arr[9];

void dfs(int j, int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';

		return;
	}
	else {
		for (int i = j; i <= N; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				arr[k] = i;
				dfs(i + 1, k + 1);
				visited[i] = 0;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	dfs(1, 0);

	return 0;
}