#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int answer = 0;

int check(vector<vector<char>>& change) {
	int ans = 0;

	int row = 1, col = 1;
	for (int i = 0; i < change.size(); i++) {
		for (int j = 1; j < change.size(); j++) {
			if (change[i][j] == change[i][j - 1]) {
				row++;
			}
			else {
				row = 1;
			}
			ans = max(row, ans);
		}
		row = 1;
	}

	for (int i = 0; i < change.size(); i++) {
		for (int j = 1; j < change.size(); j++) {
			if (change[j][i] == change[j - 1][i]) {
				col++;
			}
			else {
				col = 1;
			}
			ans = max(col, ans);
		}
		col = 1;
	}

	return ans;
}

void swap_function(vector<vector<char>>& change, vector<vector<char>>& candy, int i, int j) {
	for (int k = 0; k < 4; k++) {
		if (i + dx[k] >= 0 && i + dx[k] < change.size() && j + dy[k] >= 0 && j + dy[k] < change.size()) {
			if (change[i + dx[k]][j + dy[k]] != change[i][j]) {
				swap(change[i + dx[k]][j + dy[k]], change[i][j]);
			}
		}
		answer = check(change);
		change = candy;
	}
}



int main()
{
	int N;
	cin >> N;

	vector<vector<char>> candy(N, vector<char>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> candy[i][j];
		}
	}

	vector<vector<char>> change = candy;

	int answer = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			swap_function(change, candy, i, j);
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		answer = max(answer, ans[i]);
	}

	cout << answer << "\n";

	return 0;
}