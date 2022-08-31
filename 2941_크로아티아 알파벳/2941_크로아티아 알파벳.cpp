#include <iostream>
using namespace std;

int main()
{
	string str;

	cin >> str;

	int ans = str.length();
	int length = ans;

	for (int i = 0; i < length; i++) {
		if (str[i] == 'l' && str[i + 1] == 'j')
			ans--;

		if (str[i] == 'n' && str[i + 1] == 'j')
			ans--;

		if (str[i] == 'd' && str[i + 1] == 'z' && str[i + 2] == '=')
			ans--;

		else if (str[i] == '=')
			ans--;

		if (str[i] == '-')
			ans--;
	}

	cout << ans << endl;

	return 0;
}