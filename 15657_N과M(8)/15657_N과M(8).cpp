#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int check = 0;

void dfs(int k, vector<int>& arr, vector<int>& ans)
{
	vector<int> visit(N);

	if (k == M) {
		for (int i = 0; i < k; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		check = 0;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (visit[i] == 0 && check <= arr[i]) {
				visit[i] = 1;
				ans[k] = arr[i];
				check = ans[k];
				dfs(k + 1, arr, ans);
				visit[i] = 0;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	
	vector<int> ans(M);

	dfs(0, arr, ans);
}