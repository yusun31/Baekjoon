#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T != 0) {
		int N;
		cin >> N;

		vector<pair<int, int> > new_em(N);
		for (int i = 0; i < N; i++) {
			cin >> new_em[i].first >> new_em[i].second;
		}

		sort(new_em.begin(), new_em.end());

		vector<int> no(N);
		int temp = new_em[0].second;
		for (int i = 0; i < N; i++) {
			if (temp < new_em[i].second) {
				no[i]++;
			}
			temp = min(temp, new_em[i].second);
		}

		int answer = 0;
		for (int i = 0; i < N; i++) {
			if (no[i] == 0) {
				answer++;
			}
		}

		cout << answer << endl;

		T--;
	}

	return 0;
}