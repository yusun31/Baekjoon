#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<pair<int, int>> cow;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		cow.push_back(make_pair(x, y));
	}
	sort(cow.begin(), cow.end());

	int time = cow[0].first;
	for (int i = 0; i < N; i++) {
		if (time < cow[i].first)
			time += cow[i].first - time;
		time += cow[i].second;
	}

	cout << time << endl;

	return 0;
}