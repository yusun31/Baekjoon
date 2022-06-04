#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	
	vector<int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += arr[i];
	}

	int result = sum;
	for (int i = K; i < N; i++) {
		sum += arr[i] - arr[i - K];
		result = max(result, sum);
	}

	cout << result << endl;

	return 0;
}