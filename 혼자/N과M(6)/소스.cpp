#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
int visited[8] = { 0 };
int result[8];

void dfs(int j, int k) {
	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}
	else {
		for (int i = j - 1; i < N; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				result[k] = arr[i];
				dfs(i + 1, k + 1);
				visited[i] = 0;
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

	dfs(1, 0);

	return 0;
}