#include <iostream>
using namespace std;

int main()
{
	int X, Y;
	int x = 0, y = 0;

	cin >> X >> Y;

	int count = 0;
	if (X < Y) swap(X, Y);

	count = X + Y + Y / 10;

	cout << count << endl;

	return 0;
}