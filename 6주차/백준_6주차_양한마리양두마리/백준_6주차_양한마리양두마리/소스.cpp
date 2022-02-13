#include <iostream>
using namespace std;

char sheep[100][100] = { ' ' };
int visited[100][100] = { 0 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int H, W;

void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= H || nx < 0 || ny >= W || ny < 0)
			continue;
		if (sheep[nx][ny] == '#' && visited[nx][ny] == 0) {
			visited[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}

int main()
{
	int T;

	cin >> T;

	while (T--) {
		cin >> H >> W;

		int group = 0;

		for (int i = 0; i < H; i++)
			cin >> sheep[i];

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (sheep[i][j] == '#' && visited[i][j] == 0) {
					group++;
					dfs(i, j);
				}
			}
		}

		cout << group << endl;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				visited[i][j] = 0;
			}
		}
	}

	return 0;
}