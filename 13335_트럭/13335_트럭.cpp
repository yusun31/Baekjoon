#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int n, w, L;
	cin >> n >> w >> L;

	vector<int> truck(n);
	for (int i = 0; i < n; i++) {
		cin >> truck[i];
	}


	queue<int> q;
	int weight = 0;

	int answer = 0;
	for (int i = 0; i < n; i++) {
		while (1) {
			while (q.size() >= w) {
				weight -= q.front();
				q.pop();
				answer++;
			}
			if (weight + truck[i] <= L) {
				break;
			}
			q.push(0);
		}
		q.push(truck[i]);
		weight += truck[i];
	}

	cout << answer + w + q.size() << endl;

	return 0;
}