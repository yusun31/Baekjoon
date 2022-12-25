#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, H;
	cin >> N >> H;

	vector<int> ctite(N / 2); // 종유석
	vector<int> gmite(N / 2); // 석순
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;

		if (i % 2 == 0) { // 종유석
			ctite[(i / 2) - 1] = x;
		}
		else { // 석순
			gmite[i / 2] = x - 1;
		}
	}

	sort(ctite.begin(), ctite.end(), greater<int>());
	sort(gmite.begin(), gmite.end());
	
	vector<int> answer(H);
	int temp_g = 0;
	for (int i = 0; i < H; i++) {
		for (int j = temp_g; j < N / 2; j++) {
			if (gmite[j] >= i) {
				answer[i] += N / 2 - temp_g;
				break;
			}
			else {
				temp_g++;
			}
		}
	}
	int temp_c = 0;
	for (int i = 0; i < H; i++) {
		for (int j = temp_c; j < N / 2; j++) {
			if (H - ctite[j] > i) {
				answer[i] += temp_c;
				break;
			}
			else {
				temp_c++;
			}
		}
		if (temp_c == N / 2) answer[i] += temp_c;
	}

	int count = 0;
	int min_value = N;
	for (int i = 0; i < H; i++) {
		if (min_value > answer[i]) {
			min_value = answer[i];
			count = 1;
		}
		else if (min_value == answer[i]) {
			count++;
		}
	}
	cout << min_value << " " << count << "\n";

	return 0;
}