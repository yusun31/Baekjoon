#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;

	vector<int> ice(5000001, 0);

	int g, x;
	for (int i = 0; i < N; i++) {
		cin >> g >> x;
		ice[x] = g;
	}

	int max_a = 0;
	for (int i = 0; i <= 2 * K; i++) {
		max_a += ice[i];
	}

	int ans = max_a;
	for (int i = K + 1; i <= 1000000; i++) {
		max_a = max_a - ice[i - K - 1] + ice[i + K];
		ans = max(ans, max_a);
	}

	cout << ans << endl;

	return 0;
}