#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C;

queue<pair<int, int>> water;
queue<pair<int, int>> hedge;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int answer = 0;

int bfs(vector<vector<char>> &forest, vector<int> &end) {
	vector<vector<int>> visit(R, vector<int>(C));

	queue<pair<int, int>> nextwater, nexthedge;
	
	while (!hedge.empty()) {
		while (!water.empty()) {
			int x = water.front().first;
			int y = water.front().second;

			water.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= R || nx < 0 || ny >= C || ny < 0) continue;

				if (forest[nx][ny] == '.') {
					forest[nx][ny] = '*';
					nextwater.push({ nx,ny });
				}
			}
		}

		while (!hedge.empty()) {
			int x = hedge.front().first;
			int y = hedge.front().second;

			if (end[0] == hedge.front().first && end[1] == hedge.front().second) {
				return answer;
			}

			hedge.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= R || nx < 0 || ny >= C || ny < 0) continue;

				if (forest[nx][ny] == '.' || forest[nx][ny] == 'D' && !visit[nx][ny]) {
					forest[nx][ny] = 'S';
					nexthedge.push({ nx,ny });
					visit[nx][ny] = 1;
				}
			}
		}
		
		answer++;

		water = nextwater;
		while (!nextwater.empty()) nextwater.pop();
		hedge = nexthedge;
		while (!nexthedge.empty()) nexthedge.pop();
	}

	return -1;
}

int main()
{
	cin >> R >> C;

	vector<vector<char>> forest(R, vector<char>(C));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> forest[i][j];
		}
	}

	vector<int> end(2);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (forest[i][j] == '*') {
				water.push({ i,j });
			}
			if (forest[i][j] == 'S') {
				hedge.push({ i,j });
			}
			if (forest[i][j] == 'D') {
				end[0] = i;
				end[1] = j;
			}
		}
	}

	int check = bfs(forest, end);

	if (check != -1)
		cout << answer << "\n";
	else
		cout << "KAKTUS\n";
	return 0;
}