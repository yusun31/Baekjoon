#include <iostream>
using namespace std;

string recursive(int);

int main()
{
	int N;
	string line = "";

	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;

	line = recursive(N);

	for (int i = 0; i < N + 1; i++) {
		cout << line << "��� �亯�Ͽ���." << endl;
		line.erase(0, 4);
	}
}

string recursive(int n)
{
	string line = "";

	for (int i = 0; i < n + 1; i++) {
		if (i != n) {
			cout << line << "\"����Լ��� ������?\"" << endl;
			cout << line << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;
			cout << line << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;
			cout << line << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << endl;
			line += "____";
		}
		else {
			cout << line << "\"����Լ��� ������?\"" << endl;
			cout << line << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
		}
	}

	return line;
}