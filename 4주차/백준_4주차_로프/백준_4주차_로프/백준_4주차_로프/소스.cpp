#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	int rope;
	int r[100000] = { 0 };
	int result[10000] = { 0 };

	cin >> N;

	int re = 0;
	for (int i = 0; i < N; i++) {
		cin >> rope;
		r[i] = rope;
	}

	sort(r, r + N, greater<int>());

	for (int i = 0; i < N; i++) {
		result[i] = r[i] * (i + 1);
		if (re < result[i])
			re = result[i];
	}

	cout << re << endl;


	return 0;
}