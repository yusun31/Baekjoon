#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> wine(n + 1, 0);
	vector<int> dp(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	for (int i = 1; i <= n; i++) {
		if (i < 3) {
			dp[i] = dp[i - 1] + wine[i];
		}
		else {
			dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 2] + wine[i]);
			dp[i] = max(dp[i - 1], dp[i]);
		}
	}

	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > result)
			result = dp[i];
	}

	cout << result << "\n";

	return 0;
}