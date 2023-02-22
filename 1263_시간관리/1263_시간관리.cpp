#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int>& b) {
	return a.second > b.second;
}

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> task(N);
	for (int i = 0; i < N; i++) {
		cin >> task[i].first >> task[i].second;
	}

	sort(task.begin(), task.end(), compare);

	int max_time = task[0].second + 1;

	vector<int> time(max_time);
	int answer = -1;

	for (int i = 0; i < N; i++) {
		int check = task[i].second;
		while (time[check] != 0) {
			check--;
		}
		for (int j = check; j > check - task[i].first; j--) {
			if (j >= 0) {
				time[j] = 1;
			}
			else {
				cout << answer << "\n";
				return 0;
			}
		}
	}
	
	for (int i = 0; i < time.size(); i++) {
		if (time[i] == 0) {
			answer = i;
		}
		else {
			cout << answer << "\n";
			break;
		}
	}

	return 0;
}