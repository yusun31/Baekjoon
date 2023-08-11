#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;

	vector<int> coin(N);
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	int answer = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (K == 0) {
			break;
		}
		if (K >= coin[i]) {
			int money = K / coin[i];
			answer += money;
			K -= coin[i] * money;
		}
	}

	cout << answer << endl;

	return 0;
}