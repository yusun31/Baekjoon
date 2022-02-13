#include <iostream>
using namespace std;

int main()
{
	int N;
	int x, y;
	int xx[50] = { 0 }, yy[50] = { 0 };

	cin >> N;

	int no = 0;
	while (no != N)
	{
		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			no++;
			xx[i] = x, yy[i] = y;
		}
	}

	int temp = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (xx[i] < xx[j] && yy[i] < yy[j]) {
				temp++;
			}
		}
		cout << temp << endl;
		temp = 1;
	}

	return 0;
}