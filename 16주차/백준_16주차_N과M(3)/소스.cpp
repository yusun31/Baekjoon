#include <iostream>
using namespace std;

int arr[9];
int visited[9];
int N, M;

void dfs(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	else {
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) {
				arr[k] = i;
				dfs(k + 1);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	dfs(0);

	return 0;
}