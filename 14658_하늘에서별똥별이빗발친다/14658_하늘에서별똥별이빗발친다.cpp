#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M, L, K;

	cin >> N >> M >> L >> K;
	vector<pair<int, int>> coordinate(K + 1);

	for (int i = 1; i <= K; i++) {
		cin >> coordinate[i].first >> coordinate[i].second;
	}

	int answer = 0;
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K; j++) {
			int temp = 0;
			int x = coordinate[i].first;
			int y = coordinate[j].second;
			for (int a = 1; a <= K; a++) {
				if ((coordinate[a].first >= x && coordinate[a].first <= x + L) && (coordinate[a].second >= y && coordinate[a].second <= y + L)) {
					temp++;
				}
				answer = max(temp, answer);
			}
		}
	}

	cout << K - answer << "\n";

	return 0;
}