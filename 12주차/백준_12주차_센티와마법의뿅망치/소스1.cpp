#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, H_cen, T;

	cin >> N >> H_cen >> T;

	vector<int> H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	sort(H.begin(), H.end(), greater<int>()); // quick sort

	int count = 0;
	while (T != count) {
		if (H[0] == 1) {
			break;
		}
		else {
			H[0] = H[0] / 2;
			sort(H.begin(), H.end(), greater<int>());
		}
		count++;
	}

	if (H_cen > H[0])
		cout << "YES" << endl << count << endl;
	else
		cout << "NO" << endl << H[0] << endl;

	return 0;
}