#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> S(M);
	for (int i = 0; i < M; i++) {
		cin >> S[i];
	}

	vector<int> wok;
	for (int i = 0; i < M; i++) {
		wok.push_back(S[i]);
	}
	for (int i = 0; i < M - 1; i++) {
		for (int j = i + 1; j < M; j++) {
			if (wok[i] != S[i] + S[j]) {
				wok.push_back(S[i] + S[j]);
			}
		}
	}

	vector<int> dp(N + 1, 10001);
	for (int i = 1; i <= N; i++) {
		int divide = 10001;
		for (int j = 0; j < wok.size(); j++) {
			if (i % wok[j] == 0) {
				divide = i / wok[j];
			}
			if (wok[j] <= i) {
				dp[i] = min({ dp[i], divide, dp[i - wok[j]] + dp[wok[j]] });
			}
		}
	}

	if (dp[N] == 10001) {
		cout << "-1\n";
	}
	else {
		cout << dp[N] << "\n";
	}

	return 0;
}