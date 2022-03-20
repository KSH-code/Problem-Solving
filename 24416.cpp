#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int N; cin >> N;
    int fib[N + 10];
    fib[2] = fib[1] = 1;
    for (int i = 3; i <= N; i++) fib[i] = fib[i - 1] + fib[i - 2];
    cout << fib[N] << ' ' << N - 2;
    return 0;
}
