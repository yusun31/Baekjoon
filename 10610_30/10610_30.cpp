#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string N;

	cin >> N;

	sort(N.begin(), N.end(), greater<>());

	int sum = 0;
	if (N[N.length() - 1] != '0') {
		cout << -1 << endl;
	}
	else {
		for (int i = 0; i < N.length(); i++) {
			sum += N[i] - '0';
		}
		if (sum % 3 == 0) {
			cout << N << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	
	return 0;
}