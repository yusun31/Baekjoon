#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<int> input(N + 1, 0);
	N *= 2;

	int count = 0;
	int result = 0;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		count++;
		if (input[tmp] == 1)
			count -= 2;
		else
			input[tmp] = 1;

		result = max(count, result);
	}

	cout << result << endl;

	return 0;
}