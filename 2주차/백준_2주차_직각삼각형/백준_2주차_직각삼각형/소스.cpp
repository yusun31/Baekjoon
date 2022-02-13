#include <iostream>
using namespace std;

int main()
{
	int ang1 = 0, ang2 = 0, ang3 = 0;
	int area1 = 0, area2 = 0;

	while (1) {
		cin >> ang1 >> ang2 >> ang3;
		if (ang1 == 0)
			break;

		if (ang1 > ang2) {
			if (ang1 > ang3) {
				area1 = ang1 * ang1;
				area2 = ang2 * ang2 + ang3 * ang3;
			}
			else {
				area1 = ang3 * ang3;
				area2 = ang1 * ang1 + ang2 * ang2;
			}
		}

		else {
			if (ang1 > ang3 && ang2 > ang3) {
				area1 = ang2 * ang2;
				area2 = ang1 * ang1 + ang3 * ang3;
			}
			if (ang3 > ang2) {
				area1 = ang3 * ang3;
				area2 = ang1 * ang1 + ang2 * ang2;
			}
		}

		if (area1 == area2)
			cout << "right" << endl;
		else
			cout << "wrong" << endl;

	}

	return 0;
}