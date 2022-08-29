#include <iostream>
using namespace std;

int main()
{
    string A, B;
    char matrix[40][40];

    cin >> A >> B;

    int N = A.size(), M = B.size();
    memset(matrix, '.', sizeof(matrix));

    int locA = 0, locB = 0;

    for (int i = 0; i < N; i++) {
        if (B.find(A[i]) <= B.length()) {
            locA = i; // A의 위치
            locB = B.find(A[i]); // B의 위치
            break;
        }
    }

    for (int b = 0; b < M; b++) {
        for (int a = 0; a < N; a++) {
            if (a == locA)
                matrix[b][a] = B[b];
            if (b == locB)
                matrix[b][a] = A[a];
            cout << matrix[b][a];
        }
        cout << endl;
    }


    return 0;
}