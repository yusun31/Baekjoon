#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr;
int visited[9] = { 0 };
int result[9] = { 0 };

void dfs(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++)
			cout << result[i] << " ";
		cout << endl;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				result[k] = arr[i];
				dfs(k + 1);
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

	dfs(0);

	return 0;
}