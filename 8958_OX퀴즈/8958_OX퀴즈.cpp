#include <iostream>
using namespace std;

int main()
{
	int T;
	string str;
	char ox[80] = { ' ' };

	cin >> T;

	while (T != 0) {
		cin >> str;

		int sum = 0;
		int score = 1;
		int length = str.size();
		for (int i = 0; i < length; i++) {
			if (str[i] == 'O') {
				if (score == 0) {
					score = 1;
				}
				sum += score;
				score++;
			}
			else {
				score = 0;
				sum += score;
			}
		}

		cout << sum << endl;

		T--;
	}

	return 0;
}