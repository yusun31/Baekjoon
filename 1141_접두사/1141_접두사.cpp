#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(string a, string b)
{
	return a.size() < b.size();
};

int main()
{
	int N;

	cin >> N;

	vector<string> str(N);

	int count = N;

	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}

	sort(str.begin(), str.end(), compare);

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (str[j].substr(0, str[i].size()) == str[i]) {
				count--;
				break;
			}
		}
	}

	cout << count << endl;

	return 0;
}