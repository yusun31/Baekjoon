#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 200000001

vector<vector<int>> dijkstra(int start, int N, vector<vector<pair<int, int>>>& graph, int v[])
{
    vector<vector<int>> dist(2, vector<int>(N + 1, INF));

    for (int i = 0; i < 2; i++) {
        priority_queue<pair<int, int>> pq;

        dist[i][v[i]] = 0;
        pq.push({ 0, v[i] });

        while (!pq.empty())
        {
            int cur_dist = -pq.top().first;
            int cur_node = pq.top().second;
            pq.pop();

            for (int j = 0; j < graph[cur_node].size(); j++)
            {
                int nxt_node = graph[cur_node][j].first;
                int nxt_dist = cur_dist + graph[cur_node][j].second;

                if (nxt_dist < dist[i][nxt_node]) {
                    dist[i][nxt_node] = nxt_dist;
                    pq.push({ -nxt_dist, nxt_node });
                }
            }
        }
    }

    return dist;
}

int main()
{
    int N, E;
    cin >> N >> E;

    vector<vector<pair<int, int>>> graph(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    int v[2];
    cin >> v[0] >> v[1];

    vector<vector<int>> dist = dijkstra(1, N, graph, v);

    int answer = min(dist[0][1] + dist[0][v[1]] + dist[1][N], dist[1][1] + dist[1][v[0]] + dist[0][N]);

    if (answer >= INF) answer = -1;

    cout << answer << "\n";

    return 0;
}