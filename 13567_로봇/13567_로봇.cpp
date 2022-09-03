#include <iostream>
using namespace std;

int main()
{
	int M, n;
	int x = 0, y = 0;
	string str;
	int turn = 1;
	int result = 0;

	cin >> M >> n;

	while (n != 0) {
		cin >> str;
		int k, l;

		if (str == "MOVE") {
			cin >> k;
			if (x <= M && y <= M) {
				if (turn == 1) // right 
					x += k;
				else if (turn == 2) // up
					y += k;
				else if (turn == 3) // left
					x -= k;
				else // down
					y -= k;
			}
			else
				break;

		}

		if (str == "TURN") {
			cin >> l; // 1(right) or 0(left)
			if (l == 1) {
				if (turn == 1)
					turn = 4;
				else if (turn == 2)
					turn = 1;
				else if (turn == 3)
					turn = 2;
				else
					turn = 3;
			}
			else if (l == 0)
				if (turn == 1)
					turn = 2;
				else if (turn == 2)
					turn = 3;
				else if (turn == 3)
					turn = 4;
				else
					turn = 1;
		}

		n--;
	}

	if ((x <= M && x >= 0) && (y <= M && y >= 0))
		result = result;
	else
		result = -1;

	if (result == -1)
		cout << result << endl;
	else
		cout << x << " " << y << endl;

	return 0;
}