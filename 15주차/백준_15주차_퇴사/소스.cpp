#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> t(n, 0), p(n, 0);
	vector<int> dp(n + 1, 0);

	int result = 0;

	for (int i = 0; i < n; i++)
		cin >> t[i] >> p[i];

	for (int i = 0; i < n; i++) {
		if (t[i] + i <= n) {
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
			result = max(result, dp[i]);
		}
		dp[i + 1] = max(dp[i + 1], dp[i]);
		result = max(result, dp[i + 1]);
	}

	cout << result << endl;

	return 0;
}