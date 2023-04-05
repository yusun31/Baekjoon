#include <iostream>
#include <vector>
using namespace std;

int answer = -1;
int relation[101][101];

int dfs(int first, int second, vector<int>& visit, int no)
{
	visit[first] = 1;

	if (first == second) {
		answer = no;
		return answer;
	}

	for (int i = 1; i <= visit.size(); i++) {
		if (relation[first][i] == 1 && visit[i] == 0) {
			dfs(i, second, visit, no + 1);
		}
	}

	return answer;
}

int main()
{
	int n, first, second, m;
	cin >> n >> first >> second >> m;

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		relation[x][y] = 1;
		relation[y][x] = 1;
	}

	vector<int> visit(n + 1);

	answer = dfs(first, second, visit, 0);

	if (answer == 0) answer = -1;
	cout << answer << "\n";

	return 0;
}