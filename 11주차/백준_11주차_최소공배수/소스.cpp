#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T;

	cin >> T;

	int A, B;
	int result = 1;
	while (T != 0) {
		cin >> A >> B;

		int tmp = 1;
		if (A == 1) result = B;
		else if (B == 1) result = A;
		else {
			int AA, BB;
			if (A >= B) {
				AA = A;
				BB = B;
			}
			else {
				AA = B;
				BB = A;
			}
			while (BB != 0) {
				tmp = BB;
				BB = AA % BB;
				AA = tmp;
			}
			result = (A * B) / tmp;
		}
		cout << result << endl;

		T--;
	}

	return 0;
}