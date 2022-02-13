#include <iostream>
using namespace std;

char backyard[250][250] = { ' ' };
int visited[250][250] = { 0 };
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int R, C;
int o, v;

void dfs(int x, int y) {
	if (backyard[x][y] == 'o') o++;
	else if (backyard[x][y] == 'v') v++;
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= R || ny >= C || nx < 0 || ny < 0)
			continue;

		if (backyard[nx][ny] != '#' && visited[nx][ny] == 0) {
			visited[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}

int main()
{
	string str;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		cin >> str;
		for (int j = 0; j < C; j++) {
			backyard[i][j] = str[j];
		}
	}

	int sheep = 0, wolf = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			o = 0, v = 0;
			if (backyard[i][j] != '#' && visited[i][j] == 0) {
				dfs(i, j);
				if (o > v) sheep += o;
				else wolf += v;
			}
		}
	}

	cout << sheep << " " << wolf << endl;

	return 0;
}