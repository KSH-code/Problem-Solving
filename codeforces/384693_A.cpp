#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lm(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) return n / i;
    }
    return 1LL;
}

void solve(){
    ll a; cin >> a;

    ll b = 0;
    for (int i = 0; (1<<i) <= a; i++) b |= 1 << i;

    if (b != a) cout << b;
    else cout << lm(a);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
