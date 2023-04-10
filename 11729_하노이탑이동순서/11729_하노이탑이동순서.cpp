#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int from, int via, int to)
{
	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	else {
		hanoi(n - 1, from, to, via);
		cout << from << " " << to << "\n";
		hanoi(n - 1, via, from, to);
	}
}

int main()
{
	int N;

	cin >> N;

	cout << int(pow(2, N) - 1) << "\n";
	hanoi(N, 1, 2, 3);
}