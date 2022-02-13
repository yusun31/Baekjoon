#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001] = { 0 };
int visited[1001] = { 0 };

void dfs(int n, int v) {
	cout << v << " ";
	visited[v] = 1;

	for (int i = 1; i <= n; i++) {
		if (graph[v][i] == 1 && visited[i] == 2) {
			dfs(n, i);
		}
	}
}

void bfs(int n, int v) {
	queue<int> q;

	q.push(v);
	visited[v] = 0;
	cout << v << " ";

	while (!q.empty()) {
		int k = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (graph[k][i] == 1 && visited[i] == 1) {
				q.push(i);
				visited[i] = 0;
				cout << i << " ";
			}
		}
	}
}

int main()
{
	int N, M, V;

	cin >> N >> M >> V;

	int v1, v2;
	int count = M;
	while (count != 0) {
		cin >> v1 >> v2;
		graph[v1][v2] = graph[v2][v1] = 1;
		visited[v1] = visited[v2] = 2;
		count--;
	}

	dfs(N, V);
	cout << endl;
	bfs(N, V);

	return 0;
}