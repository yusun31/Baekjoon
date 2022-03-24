#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N, H_cen, T;

	cin >> N >> H_cen >> T;

	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		pq.push(input);
	}

	int count = 0;
	while (T != count) {
		int tmp = pq.top();
		if (tmp < H_cen) {
			cout << "YES" << endl << count << endl;
			return  0;
		}
		else if(tmp > 1) {
			tmp = tmp / 2;
			pq.push(tmp);
		}
		pq.pop();
		count++;
	}

	if (H_cen > pq.top())
		cout << "YES" << endl << count << endl;
	else
		cout << "NO" << endl << pq.top() << endl;

	return 0;
}