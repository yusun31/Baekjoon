#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define SIZE 20001
#define INF 1000000000

vector<pair<int, int>> graph[SIZE];

vector<int> dijkstra(int start, int V) {
	vector<int> dist(V + 1, INF);

	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_node = pq.top().second;
		pq.pop();

		if (dist[cur_node] < cur_dist) continue;

		for (int i = 0; i < graph[cur_node].size(); i++) {
			int next_node = graph[cur_node][i].first;
			int next_dist = cur_dist + graph[cur_node][i].second;

			if (dist[next_node] > next_dist) {
				dist[next_node] = next_dist;
				pq.push({ -next_dist, next_node });
			}
		}
	}

	return dist;
}

int main()
{
	int V, E, K;
	cin >> V >> E >> K;


	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	vector<int> dist = dijkstra(K, V);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
	
	return 0;
}