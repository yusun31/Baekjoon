#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;

	cin >> str;

	int n = str.length();
	int k = n;

	for (int i = 0; i < k; i++) {
		if (str[i] == 'l' && str[i + 1] == 'j')
			n--;

		if (str[i] == 'n' && str[i + 1] == 'j')
			n--;

		if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=')
			n--;

		else if (str[i] == '=')
			n--;

		if (str[i] == '-')
			n--;
	}

	cout << n << endl;

	return 0;
}