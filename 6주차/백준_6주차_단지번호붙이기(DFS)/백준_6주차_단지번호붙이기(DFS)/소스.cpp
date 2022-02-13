#include <iostream>
#include <string>
using namespace std;

int dan[25][25] = { 0 };
int visited[25][25] = { 0 };
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int N;
int cnt;

void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= N || ny >= N || nx < 0 || ny < 0)
			continue;

		if (dan[nx][ny] == 1 && visited[nx][ny] == 0) {
			visited[nx][ny] = 1;
			cnt += 1;
			dfs(nx, ny);
		}
	}
}

int main()
{
	string str;
	int re = 0;
	int arr[625] = { 0 };

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			dan[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dan[i][j] == 1 && visited[i][j] == 0) {
				cnt = 1;
				dfs(i, j);
				cout << cnt << endl;
				re++;
			}
		}
	}

	cout << re << endl;

	return 0;
}