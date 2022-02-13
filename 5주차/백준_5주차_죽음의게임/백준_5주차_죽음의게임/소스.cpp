#include <iostream>
using namespace std;

int main()
{
	int N, K;
	int arr[150] = { 0 };
	int order[150] = { 0 };

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		order[0] = arr[0];
		order[i + 1] = arr[order[i]];
	}

	int result = 0;
	for (int i = 0; i <= N; i++) {
		if (order[i] == K) {
			result = i + 1;
			break;
		}
	}

	if (result == 0)
		cout << "-1" << endl;
	else
		cout << result << endl;


	return 0;
}