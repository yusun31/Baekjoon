#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;

	int x, y;
	for (int i = 0; i < T; i++) {
		cin >> x >> y;
		int result = 0;

		int temp = y - x;
		if (sqrt(temp) - int(sqrt(temp)) == 0) {
			result = sqrt(temp) * 2 - 1;
		}
		else {
			result = sqrt(temp) * 2;
		}

		cout << result <<"\n";
	}

	return 0;
}