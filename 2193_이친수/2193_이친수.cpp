#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<long long> pinary(N + 1);
	pinary[0] = 0;
	pinary[1] = 1;
	for (int i = 2; i <= N; i++) {
		pinary[i] = pinary[i - 1] + pinary[i - 2];
	}

	long long answer = pinary[N];
	cout << answer << endl;

	return 0;
}