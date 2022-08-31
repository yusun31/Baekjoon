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

	// �������� ���� ������ �� ���� ��ȣ ���ϱ�
	int maybe_answer = 0;
	for (int i = 1; i <= N; i++) {
		if (PK[i] == maybe_max) {
			maybe_answer = i;
			break; // ������ ���� ��� ���� ���� ��ȣ �� ���
		}
	}

	// ������ũ ���� ����
	vector<int> answer(N + 1);
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= N; j++) {
			if (cake[i] == j) {
				answer[j]++;
			}
		}
	}

	// ���������� ���� �������� ��ȣ ���ϱ�
	int real_max = 0;
	for (int i = 1; i <= N; i++) {
		real_max = max(real_max, answer[i]);
	}
	int real_answer = 0;
	for (int i = 1; i <= N; i++) {
		if (answer[i] == real_max) {
			real_answer = i;
			break; // ������ ���� ��� ���� ���� ��ȣ �� ���
		}
	}

	cout << maybe_answer << "\n" << real_answer << "\n";

	return 0;
}