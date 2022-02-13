#include <iostream>
using namespace std;

int main()
{
	int N;
	int grade[100] = { 0 };
	int count = 0;
	int no = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> grade[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (grade[j] >= grade[i]) {
				count += grade[j] - grade[i] + 1;
				grade[j] -= grade[j] - grade[i] + 1;
			}
		}
	}

	cout << count << endl;

	return 0;
}