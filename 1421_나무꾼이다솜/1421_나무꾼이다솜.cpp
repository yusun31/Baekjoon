#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, C, W;
	cin >> N >> C >> W;

	vector<int> log(N);
	for (int i = 0; i < N; i++) {
		cin >> log[i];
	}

	sort(log.begin(), log.end(), greater<int>());

	long long answer = 0;
	for (int i = log[0]; i > 0; i--) {
		int cut = 0, sum = 0;
		long long price = 0;
		for (int j = 0; j < N; j++) {
			cut = (log[j] - 1) / i;
			sum = ((log[j] / i) * i * W) - (cut * C);
			if (sum > 0) price += sum;
		}
		answer = max(price, answer);
	}

	cout << answer << "\n";

	return 0;
}