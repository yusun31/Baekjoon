#include <iostream>
#include <algorithm>
using namespace std;

int dan[25][25] = { 0 };
int visited[25][25] = { 0 };
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int N;
int group;

void dfs(int x, int y) {
	visited[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= N || nx < 0 || ny >= N || ny < 0)
			continue;

		if (dan[nx][ny] == 1 && visited[nx][ny] == 0) {
			group++;
			visited[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}

int main()
{
	int cnt_group[625] = { 0 };
	string str;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			dan[i][j] = str[j] - '0';
		}
	}

	int count = 0;
	int k = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dan[i][j] == 1 && visited[i][j] == 0) {
				group = 1;
				dfs(i, j);
				count++;
				if (group != 0) {
					cnt_group[k++] = group;
				}
			}
		}
	}

	cout << count << endl;

	sort(cnt_group, cnt_group + count, less<int>());
	for (int i = 0; i < count; i++) {
		cout << cnt_group[i] << endl;
	}

	return 0;
}