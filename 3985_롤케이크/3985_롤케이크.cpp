#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int L, N;
	
	cin >> L >> N;

	vector<int> cake(L + 1);
	vector<int> PK(N + 1);
	int maybe_max = 0;
	for (int i = 1; i <= N; i++) {
		int P, K;
		cin >> P >> K;

		PK[i] = K - P + 1;

		maybe_max = max(maybe_max, PK[i]);

		for (int j = P; j <= K; j++) {
			if (cake[j] == 0) {
				cake[j] = i;
			}
		}
	}

	// 예상으로 많이 가져갈 것 같은 번호 구하기
	int maybe_answer = 0;
	for (int i = 1; i <= N; i++) {
		if (PK[i] == maybe_max) {
			maybe_answer = i;
			break; // 개수가 같을 경우 가장 작은 번호 값 출력
		}
	}

	// 롤케이크 개수 세기
	vector<int> answer(N + 1);
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= N; j++) {
			if (cake[i] == j) {
				answer[j]++;
			}
		}
	}

	// 최종적으로 많이 가져가는 번호 구하기
	int real_max = 0;
	for (int i = 1; i <= N; i++) {
		real_max = max(real_max, answer[i]);
	}
	int real_answer = 0;
	for (int i = 1; i <= N; i++) {
		if (answer[i] == real_max) {
			real_answer = i;
			break; // 개수가 같을 경우 가장 작은 번호 값 출력
		}
	}

	cout << maybe_answer << "\n" << real_answer << "\n";

	return 0;
}