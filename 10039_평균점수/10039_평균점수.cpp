#include <iostream>
using namespace std;

int main()
{
    int grade[5];
    int sum = 0;
    int avg;

    for (int i = 0; i < 5; i++) {
        cin >> grade[i];

        if (grade[i] > 100 && grade[i] < 0)
            return 0;
        else if (grade[i] >= 40)
            grade[i] = grade[i];
        else
            grade[i] = 40;

        sum += grade[i];
    }

    avg = sum / 5;

    cout << avg << endl;

    return 0;
}