#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n;

	priority_queue<int, vector<int>, greater<int>> pq;

	scanf("%d", &n);

	int x;
	while (n != 0) {
		scanf("%d", &x);

		if (x == 0) {
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}

		else {
			pq.push(x);
		}

		n--;
	}

	return 0;
}