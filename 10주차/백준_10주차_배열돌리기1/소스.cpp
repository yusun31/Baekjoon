#include <iostream>
using namespace std;

int main()
{
	int N, M, R;
	
	cin >> N >> M >> R;

	int arr[300][300] = { 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}



	return 0;
}