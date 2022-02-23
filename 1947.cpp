#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    ll n[N + 1]; n[0] = n[1] = 0;
    n[2] = 1;
    for (int i = 3; i<=N;i++) n[i] = ((n[i-1] + n[i-2]) * (i-1)) % (ll)(1e9);
    cout << n[N] << '\n';
    return 0;
}
