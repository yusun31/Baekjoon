#include <iostream>
using namespace std;

int main()
{
	int N, M, L;
	int ball[100] = { 0 };
	int index = 0;
	int sum = 0;

	cin >> N >> M >> L;

	ball[0]++;
	while (1) {
		if (ball[index] == M)
			break;

		else {
			if (ball[index] % 2 == 0) {
				index = index - L;
				if (index < 0) {
					index = index + N;
				}
			}

			else {
				index = index + L;
				if (index >= N) {
					index = index - N;
				}
			}
		
			ball[index]++;
			sum++;
		}
	}

	cout << sum << endl;

	return 0;
}