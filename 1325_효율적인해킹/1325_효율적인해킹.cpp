#include <iostream>
#include <vector>
using namespace std;

void dfs(int origin, int i, vector<vector<int>>& computer, vector<int>& ans, vector<int>& visit) {
	if (visit[i] != 0) {
		return;
	}
	else {
		visit[i] = 1;
		ans[origin]++;
		for (int j = 0; j < computer[i].size(); j++) {
			dfs(origin, computer[i][j], computer, ans, visit);
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<int>> computer(N + 1);
	for (int i = 0; i < M; i++) {
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;
		computer[tmp2].push_back(tmp1);
	}

	vector<int> ans(N + 1);
	for (int i = 1; i <= N; i++) {
		vector<int> visit(N + 1);
		dfs(i, i, computer, ans, visit);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		answer = max(ans[i], answer);
	}

	for (int i = 1; i <= N; i++) {
		if (answer == ans[i]) {
			cout << i << " ";
		}
	}

	return 0;
}