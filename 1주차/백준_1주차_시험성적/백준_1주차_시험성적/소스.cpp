#include <iostream>
using namespace std;

int main()
{
    int grade;
    char result;

    cin >> grade;
    if (grade > 100 || grade < 0)
        return 0;
    else {
        if (grade <= 100 && grade >= 90) result = 'A';
        else if (grade >= 80) result = 'B';
        else if (grade >= 70) result = 'C';
        else if (grade >= 60) result = 'D';
        else result = 'F';
    }
    cout << result;

    return 0;
}