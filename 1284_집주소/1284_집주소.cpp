#include <iostream>
using namespace std;

int main()
{
    string str;
    int length = 0;

    while (1) {
        cin >> str;

        if (str == "0")
            break;

        int n = str.length();
        int sum = n + 1;

        for (int i = 0; i < n; i++) {
            if (str[i] == '0') {
                length = 4;
            }
            else if (str[i] == '1') {
                length = 2;
            }
            else {
                length = 3;
            }
            sum += length;
        }

        cout << sum << endl;

    }

    return 0;
}