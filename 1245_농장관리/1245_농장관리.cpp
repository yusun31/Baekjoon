#include <iostream>
#include <vector>
using namespace std;

int N, M;
int mountain[100][70] = { 0 };
int visited[100][70] = { 0 };
int dx[8] = { 1,0,-1,0, 1, -1, 1, -1 };
int dy[8] = { 0,1,0,-1, 1, -1, -1, 1 };
bool peak = true;

void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= N || ny >= M || nx < 0 || ny < 0)
			continue;

		if (mountain[x][y] < mountain[nx][ny])
			peak = false;

		if (visited[nx][ny] == 0 && mountain[x][y] == mountain[nx][ny]) {
			visited[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mountain[i][j];
		}
	}

	int count = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0 && mountain[i][j] > 0) {
				peak = true;
				dfs(i, j);
				if (peak == true)
					count++;
			}
		}
	}

	cout << count << endl;

	return 0;
}
}