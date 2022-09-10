#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int K;

	cin >> K;

	vector<int> AB(2, 0);

	char str = 'A';
	AB[0]++;

	for (int i = 0; i < K; i++) {
		int tmp = AB[0];
		AB[0] = AB[1];
		AB[1] = tmp + AB[1];
	}

	for (int i = 0; i < 2; i++)
		cout << AB[i] << " ";
	cout << endl;

	return 0;
}