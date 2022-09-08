#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K;

	cin >> N >> K;
	vector<char> hamburger(N);

	for (int i = 0; i < N; i++)
		cin >> hamburger[i];

	int count = 0;
	for (int i = 0; i < N; i++) {
		if (hamburger[i] == 'P') {
			for (int j = i - K; j <= i + K; j++) {
				if (j >= 0 && j < N && hamburger[j] == 'H') {
					count++;
					hamburger[j] = 'N';
					break;
				}
			}
		}
	}

	cout << count << endl;

	return 0;
}