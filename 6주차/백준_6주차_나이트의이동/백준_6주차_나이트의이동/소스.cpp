#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int chess[300][300];
int visited[300][300];
int dx[8] = { 2,1,2,1,-2,-1,-2,-1 };
int dy[8] = { 1,2,-1,-2,1,2,-1,-2 };
int l;
int fx, fy;
queue<pair<int, int>> q;

void bfs(int x, int y) {
	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == fx && y == fy) {
			cout << chess[x][y] << endl;
			while (!q.empty()) {
				q.pop();
			}
			break;
		}

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < l && ny < l && nx >= 0 && ny >= 0 && visited[nx][ny] == 0) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
				chess[nx][ny] = chess[x][y] + 1;
			}
		}
	}
}

int main()
{
	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> l;

		memset(chess, 0, sizeof(chess));
		memset(visited, 0, sizeof(visited));

		int x, y;
		cin >> x >> y;
		cin >> fx >> fy;

		bfs(x, y);
	}

	return 0;
}