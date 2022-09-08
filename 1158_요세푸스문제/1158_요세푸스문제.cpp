#include <iostream>
using namespace std;

int main()
{
	int N, K;
	int num[5001];

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		num[i] = i;
	}

	int temp = 0;
	cout << "<";
	while (N != 0) {
		for (int i = 1; i <= N; i++) {
			temp = (temp + K) % N;
			if (temp == 0)
				temp = N;
			if (N == 1)
				cout << num[temp] << ">";
			else
				cout << num[temp] << ", ";
			for (int j = temp; j <= N; j++)
				num[j] = num[j + 1];
			temp--;
			N--;
		}
	}

	return 0;
}
