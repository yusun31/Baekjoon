#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<string> BW(N);
	vector<string> WB(N);
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < 4; j++) {
				BW[i] += "BW";
				WB[i] += "WB";
			}
		}
		else {
			for (int j = 0; j < 4; j++) {
				BW[i] += "WB";
				WB[i] += "BW";
			}
		}
	}

	vector<vector<char>> chess(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> chess[i][j];
		}
	}
	
	int answer = 65;
	for (int i = 0; i < N - 7; i++) {
		for (int j = 0; j < M - 7; j++) {
			int BW_check = 0;
			int WB_check = 0;
			for (int k = i; k < i + 8; k++) {
				for (int m = j; m < j + 8; m++) {
					if (BW[k - i][m - j] != chess[k][m]) {
						BW_check++;
					}
					if (WB[k - i][m - j] != chess[k][m]) {
						WB_check++;
					}
				}
			}				
			answer = min({ answer,BW_check,WB_check });
		}
	}

	cout << answer << "\n";

	return 0;
}