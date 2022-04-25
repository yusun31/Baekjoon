#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
int visited[7] = { 0 };
int result[7];

void dfs(int j, int k) {
	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << result[i] << " ";
		cout << "\n";
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visited[i] == 0) {
				result[k] = arr[i];
				dfs(j, k + 1);
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	dfs(0, 0);

	return 0;
}