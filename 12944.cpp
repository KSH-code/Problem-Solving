#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    if (a > b) return a / gcd(a, b) * b;
    else return b / gcd(a, b) * a;
}
int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    ll N, M; cin >> N >> M;
    ll arr[M]; for (int i = 0; i < M; i++) cin >> arr[i];

    ll result = 0;
    for (int i = 1; i < (1 << M); i++)
    {
        int bc = 0;
        ll mul = 1;
        for (int j = 0; j < M; j++) {
            if (i & (1 << j)) {
                mul = lcm(mul, arr[j]);
                if (mul > N) {
                    bc = -1;
                    break;
                }
                bc++;
            }
        }
        if (bc == -1) continue;
        if (bc & 1) {
            result += N/mul;
        } else {
            result -= N/mul;
        }
    }

    cout << result;
    return 0;
}
