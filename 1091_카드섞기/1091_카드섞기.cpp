#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<int> P(N);
	vector<int> S(N);

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	vector<int> answer(N);
	for (int i = 0; i < N; i++) {
		answer[i] = i % 3;
	}

	vector<int> P_change = P;
	vector<int> temp(N);
	int tmp = 0;
	int ans = 0;
	while (temp != answer) {
		if (P == answer) {
			break;
		}
		if (temp == P) {
			ans = -1;
			break;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (S[j] == i) {
					temp[i] = P_change[j];
				}
			}
		}
		P_change = temp;
		ans++;
	}

	cout << ans << endl;

	return 0;
}