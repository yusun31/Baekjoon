#include <iostream>
using namespace std;

int main()
{
	int N, M;

	cin >> N >> M;

	int count = 0;
	while (N != 0) {
		if (N % M == 0)
			break;
		else if (N % M == 1) 
			count--;
	}

	cout << count << endl;

	return 0;
}