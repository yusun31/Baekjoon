#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M, B;
	cin >> N >> M >> B;

	vector<vector<int>> block(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> block[i][j];
		}
	}

	int min = 256, max = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (min > block[i][j]) {
				min = block[i][j];
			}
			if (max < block[i][j]) {
				max = block[i][j];
			}
		}
	}

	vector<int> time(max - min + 1);
	vector<int> height(max - min + 1, B);
	for (int i = min; i <= max; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (block[j][k] > i) {
					time[i - min] += 2 * abs(block[j][k] - i);
					height[i - min] += (block[j][k] - i);
				}
				else if (block[j][k] < i) {
					time[i - min] += 1 * abs(block[j][k] - i);
					height[i - min] += (block[j][k] - i);
				}
			}
		}
	}
	
	int min_time = 100000000000;
	int max_height = -1;
	for (int i = 0; i < time.size(); i++) {
		if (min_time >= time[i] && time[i] >= 0 && height[i] >= 0) {
			min_time = time[i];
			max_height = i + min;
		}
	}

	cout << min_time << " " << max_height << endl;

	return 0;
}