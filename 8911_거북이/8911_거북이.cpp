#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int T;

	cin >> T;

	vector<string> str(T);
	for (int i = 0; i < T; i++) {
		cin >> str[i];
	}

	int dir_x[4] = { 0,-1,0,1 };
	int dir_y[4] = { 1,0,-1,0 };
	int result = 0;
	for (int i = 0; i < T; i++) {
		int con = 0;
		int plus_x = 0, minus_x = 0, plus_y = 0, minus_y = 0;
		int dx = 0, dy = 0;
		for (int j = 0; j < str[i].length(); j++) {
			if (str[i][j] == 'F') {
				dx += dir_x[con];
				dy += dir_y[con];
			}
			else if (str[i][j] == 'B') {
				dx -= dir_x[con];
				dy -= dir_y[con];
			}
			else if (str[i][j] == 'L') {
				con++;
				if (con > 3) con = 0;
			}
			else {
				con--;
				if (con < 0) con = 3;
			}
			if (dx > 0) plus_x = max(plus_x, dx);
			else if (dx < 0) minus_x = min(minus_x, dx);
			if (dy > 0) plus_y = max(plus_y, dy);
			else if (dy < 0) minus_y = min(minus_y, dy);
		}
		result = (plus_x - minus_x) * (plus_y - minus_y);
		cout << result << endl;
	}

	return 0;
}