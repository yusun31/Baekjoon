#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result[101];
int cnt = 0;

void dfs(int i, int k, vector<int>& n, vector<int>& visit) {
	if (visit[k] == 1) {
		if (i == k) {
			result[cnt++] = k;
		}
	}
	else {
		visit[k] = 1;
		dfs(i, n[k], n, visit);
	}
}

int main()
{
	int N;
	cin >> N;
	
	vector<int> number(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> number[i];
	}

	vector<int> count(N + 1);
	for (int i = 1; i <= N; i++) {
		vector<int> visit(N + 1);
		dfs(i, i, number, visit);
	}

	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}