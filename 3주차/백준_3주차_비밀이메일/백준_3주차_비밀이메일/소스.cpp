#include <iostream>
using namespace std;

int main()
{
	int R = 0, C = 0;
	int N;
	string str;
	char arr[100][100] = { ' ' };

	cin >> str;

	N = str.length();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i * j == N && i <= j) {
				if (R < i) {
					R = i;
					C = j;
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			arr[i][j] = str[i + j * R];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j];
		}
	}

	return 0;
}