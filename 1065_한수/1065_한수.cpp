#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	string str = to_string(N);

	int result = 0;
	vector<int> hansu(str.size());
	if (str.size() > 2) {
		result += 99;
		if (N != 1000) {
			for (int i = 100; i <= N; i++) {
				hansu[0] = i / 100;
				hansu[1] = (i - 100 * hansu[0]) / 10;
				hansu[2] = (i - 100 * hansu[0] - 10 * hansu[1]) / 1;
				if (hansu[0] - hansu[1] == hansu[1] - hansu[2]) {
					result++;
				}
			}
		}
		else {
			for (int i = 100; i < N; i++) {
				hansu[0] = i / 100;
				hansu[1] = (i - 100 * hansu[0]) / 10;
				hansu[2] = (i - 100 * hansu[0] - 10 * hansu[1]) / 1;
				if (hansu[0] - hansu[1] == hansu[1] - hansu[2]) {
					result++;
				}
			}
		}

	}
	else {
		result = N;
	}

	cout << result << "\n";

	return 0;
}