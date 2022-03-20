#include <iostream>
using namespace std;
typedef unsigned long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll N; cin >> N;
    if (N == 1) {
        cout << 4;
        return 0;
    } else if (N == 2) {
        cout << 6;
        return 0;
    }
    ll fibo[N + 30];
    fibo[1] = fibo[2] = 1;
    for (int i = 3; i <= N; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];

    cout << fibo[N] * 4 + fibo[N - 1] * 2;
    return 0;
}
