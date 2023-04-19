#include <iostream>
using namespace std;

int main()
{
	int X;
	cin >> X;

	string rest = "";
	while (X != 0) {
		if (X % 2 == 0) rest += "0";
		else rest += "1";
		X /= 2;
	}

	int answer = 0;
	for (int i = 0; i < rest.size(); i++) {
		if (rest[i] == '1') answer++;
	}

	cout << answer;

	return 0;
} 