#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	string result;
	int chess[6][6] = { 0 };
	int x[36] = { 0 }, y[36] = { 0 };

	for (int i = 0; i < 36; i++) {
		cin >> str;

		char str_i = str[1] - '0';
		int alpha, no;

		alpha = str[0] - 'A';
		no = str_i - 1;

		chess[alpha][no]++;

		x[i] = alpha;
		y[i] = no;
	}

	for (int i = 0; i < 36; i++) {
		if (i < 35) {
			if (x[i] == 0) {
				if (y[i] == 0) {
					if ((x[i] == x[i + 1] - 2 && y[i] == y[i + 1] - 1) || (x[i] == x[i + 1] - 1 && y[i] == y[i + 1] - 2))
						result = "Valid";
					else {
						result = "Invalid";
						break;
					}
				}
				else {
					if ((x[i] == x[i + 1] - 2 && y[i] == y[i + 1] + 1) || (x[i] == x[i + 1] - 2 && y[i] == y[i + 1] - 1) || (x[i] == x[i + 1] - 1 && y[i] == y[i + 1] + 2) || (x[i] == x[i + 1] - 1 && y[i] == y[i + 1] - 2))
						result = "Valid";
					else {
						result = "Invalid";
						break;
					}
				}
			}

			else if (x[i] == 5) {
				if (y[i] == 5) {
					if ((x[i] == x[i + 1] + 2 && y[i] == y[i + 1] + 1) || (x[i] == x[i + 1] + 1 && y[i] == y[i + 1] + 2))
						result = "Valid";
					else {
						result = "Invalid";
						break;
					}
				}
				else {
					if ((x[i] == x[i + 1] + 2 && y[i] == y[i + 1] - 1) || (x[i] == x[i + 1] + 2 && y[i] == y[i + 1] + 1) || (x[i] == x[i + 1] + 1 && y[i] == y[i + 1] + 2) || (x[i] == x[i + 1] + 1 && y[i] == y[i + 1] - 2))
						result = "Valid";
					else {
						result = "Invalid";
						break;
					}
				}
			}

			else {
				if ((x[i] == x[i + 1] + 1 && y[i] == y[i + 1] + 2) || (x[i] == x[i + 1] + 1 && y[i] == y[i + 1] - 2) || (x[i] == x[i + 1] - 1 && y[i] == y[i + 1] + 2) || (x[i] == x[i + 1] - 1 && y[i] == y[i + 1] - 2) || (x[i] == x[i + 1] + 2 && y[i] == y[i + 1] + 1) || (x[i] == x[i + 1] + 2 && y[i] == y[i + 1] - 1) || (x[i] == x[i + 1] - 2 && y[i] == y[i + 1] + 1) || (x[i] == x[i + 1] - 2 && y[i] == y[i + 1] - 1))
					result = "Valid";
				else {
					result = "Invalid";
					break;
				}
			}
		}
		else {
			if (x[35] == 0) {
				if (y[35] == 0) {
					if ((x[35] == x[0] - 2 && y[35] == y[0] - 1) || (x[35] == x[0] - 1 && y[35] == y[0] - 2))
						result = "Valid";
					else {
						result = "Invalid";
						break;
					}
				}
				else {
					if ((x[35] == x[0] - 2 && y[35] == y[0] - 1) || (x[35] == x[0] - 2 && y[35] == y[0] + 1) || (x[35] == x[0] - 1 && y[35] == y[0] + 2) || (x[35] == x[0] - 1 && y[35] == y[0] - 2))
						result = "Valid";
					else {
						result = "Invalid";
						break;
					}
				}
			}

			else if (x[35] == 5) {
				if (y[35] == 5) {
					if ((x[35] == x[0] + 2 && y[35] == y[0] - 1) || (x[35] == x[0] + 2 && y[35] == y[0] + 1))
						result = "Valid";
					else {
						result = "Invalid";
						break;
					}
				}
				else {
					if ((x[35] == x[0] + 2 && y[35] == y[0] - 1) || (x[35] == x[0] + 2 && y[35] == y[0] + 1) || (x[35] == x[0] + 1 && y[35] == y[0] + 2) || (x[35] == x[0] + 1 && y[35] == y[0] - 2))
						result = "Valid";
					else {
						result = "Invalid";
						break;
					}
				}
			}

			else {
				if ((x[35] == x[0] + 1 && y[35] == y[0] + 2) || (x[35] == x[0] + 1 && y[35] == y[0] - 2) || (x[35] == x[0] - 1 && y[35] == y[0] + 2) || (x[35] == x[0] - 1 && y[35] == y[0] - 2) || (x[35] == x[0] + 2 && y[35] == y[0] + 1) || (x[35] == x[0] + 2 && y[35] == y[0] - 1) || (x[35] == x[0] - 2 && y[35] == y[0] + 1) || (x[35] == x[0] - 2 && y[35] == y[0] - 1))
					result = "Valid";
				else {
					result = "Invalid";
					break;
				}
			}
		}
	}

	if (result == "Invalid") {
		cout << result << endl;
		return 0;
	}
	else {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (chess[i][j] > 1 || chess[i][j] < 1) {
					result = "Invalid";
					break;
				}
				else
					result = "Valid";
			}
			if (result == "Invalid")
				break;
		}
	}

	cout << result << endl;

	return 0;
}