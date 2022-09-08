#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<string> input(N);
	vector<string> str(N);
	vector<int> cnt(1000, 0);

	for (int i = 0; i < N; i++) {
		cin >> input[i];
		str[i] = input[i];
	}
	sort(input.begin(), input.end());
	sort(str.begin(), str.end());
	str.erase(unique(str.begin(), str.end()), str.end());

	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < input.size(); j++) {
			if (str[i] == input[j]) {
				cnt[i] = count(input.begin(), input.end(), input[j]);
				break;
			}
		}
	}

	int k = 0;
	int max = 0;
	for (int i = 0; i < str.size(); i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			k = i;
		}
		else {
			continue;
		}
	}

	cout << str[k] << endl;

	return 0;
}