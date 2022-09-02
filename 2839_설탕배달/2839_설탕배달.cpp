#include <iostream>
using namespace std;

int main()
{
	int N;

	cin >> N;

	int count = 2666;
	for (int i = 0; i <= 1666; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (N == 5 * j + 3 * i) {
				if (count > i + j)
					count = i + j;
			}
		}
	}


	if (count == 2666)
		cout << "-1" << endl;
	else
		cout << count << endl;

	return 0;
}