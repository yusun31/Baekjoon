#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<int> card(N + 1, 0);
	vector<int> dp(N);
	for (int i = 1; i <= N; i++) {
		cin >> card[i];
	}

	for (int i = 1; i <= N; i++) {
		dp[i - 1] = card[i] * (N / i);
		while (N % i != 0) {
			dp[i - 1] += card[N % i];
			break;
		}
	}


	int result = 0;
	for (int i = 0; i < N; i++) {
		if (result < dp[i])
			result = dp[i];
	}
	cout << result << endl;

	return 0;
}