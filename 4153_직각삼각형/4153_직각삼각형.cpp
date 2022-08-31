#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ang(3);

	while (1) {
		for (int i = 0; i < 3; i++) {
			cin >> ang[i];
		}
		if (ang[0] == 0 && ang[1] == 0 && ang[2] == 0) {
			break;
		}

		int max_ang = max(ang[0], max(ang[1], ang[2]));

		int area1 = 0, area2 = 0;
		for (int i = 0; i < 3; i++) {
			if (max_ang != ang[i]) {
				area1 += ang[i] * ang[i];
			}
			else {
				area2 = ang[i] * ang[i];
			}
		}

		if (area1 == area2)
			cout << "right" << endl;
		else
			cout << "wrong" << endl;

	}

	return 0;
}