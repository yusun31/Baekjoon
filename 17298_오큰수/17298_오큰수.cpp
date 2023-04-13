#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<int> input(N);
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}

	vector<int> ans(N);
	stack<int> s;
	ans[N - 1] = -1;
	s.push(input[N - 1]);
	for (int i = N - 2; i >= 0; i--) {
		while (!s.empty() && input[i] >= s.top()) {
			s.pop();
		}
		if (!s.empty()) {
			ans[i] = s.top();
		}
		else {
			ans[i] = -1;
		}
		s.push(input[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}