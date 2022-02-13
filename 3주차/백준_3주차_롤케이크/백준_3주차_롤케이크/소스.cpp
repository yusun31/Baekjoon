#include <iostream>
using namespace std;

int main()
{
	int L, N;
	int x, y;
	int sum1 = 0;
	int sum2[100] = { 0 };
	int a[1000] = { 0 };

	cin >> L >> N;

	int max = 0;
	int num = 0;
	for (int i = 1; i <= N; i++) {
		cin >> x >> y;

		sum1 = y - x + 1;
		if (max < sum1) {
			max = sum1;
			num = i;
		}
		for (int j = x; j <= y; j++) {
			if (a[j] == 0) {
				a[j] = i;
			}
		}
	}

	int real_max = 0;
	int real_num = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			if (a[j] == i) {
				sum2[i]++;
				if (real_max < sum2[i]) {
					real_max = sum2[i];
					real_num = i;
				}
			}
		}
	}
	cout << num << endl;
	cout << real_num << endl;

	return 0;
}