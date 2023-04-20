#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000000
#define SIZE 1001

vector<pair<int, int>> bus[SIZE];

vector<int> dijkstra(int start, int N) {
	vector<int> dist(N + 1, INF);

	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (dist[cur_node] < cur_dist) continue;

		for (int i = 0; i < bus[cur_node].size(); i++) {
			int next_node = bus[cur_node][i].first;
			int next_dist = cur_dist + bus[cur_node][i].second;

			if (dist[next_node] > next_dist) {
				dist[next_node] = next_dist;
				pq.push({ -next_dist,next_node });
			}
		}
	}

	return dist;
}

int main()
{
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int s, e, c;
		cin >> s >> e >> c;
		bus[s].push_back({ e,c });
	}

	int start, end;
	cin >> start >> end;

	vector<int> dist = dijkstra(start, N);

	cout << dist[end];

	return 0;
}