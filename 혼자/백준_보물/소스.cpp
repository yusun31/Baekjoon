#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    int S = 0;

    cin >> N;
    vector<int> A(N);
    vector<int> B(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());

    for (int i = 0; i < N; i++)
        S += A[i] * B[i];

    cout << S << endl;

    return 0;
}