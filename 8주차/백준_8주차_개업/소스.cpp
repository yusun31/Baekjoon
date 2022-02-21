#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;

	cin >> N >> M;

	vector<int> wok(M);
	vector<int> dp(M);

	for (int i = 0; i < M; i++)
		cin >> wok[i];
	sort(wok.begin(), wok.end(), greater<int>());


	return 0;
}