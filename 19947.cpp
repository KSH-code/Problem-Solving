#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
    int N, M; cin >> N >> M;
    long long arr[M + 10];
    arr[0] = N; arr[1] = N * 1.05; arr[2] = arr[1] * 1.05; arr[3] = N * 1.2;
    for (int i = 4; i <= M; i++)
        arr[i] = max({arr[i - 3] * 1.2, i - 5 >= 0 ? arr[i - 5] * 1.35 : 0, arr[i - 1] * 1.05});

    cout << arr[M];
    return 0;
}
