#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll N, M; cin >> N >> M;
    ll result = 0;
    set<ll> s;
    for (ll i = 1; i*i <= N*M; i++) {
        s.insert(i*i);
    }
    for (ll i = 1; i <= N; i++) {
        set<ll> check;
        for (ll j = 1; j * j <= M; j++) {
            for (ll k = i*j; k <= N * M; k += i * j) {
                ll c = k / (i*j);
                if (c > M) break;
                check.insert(c);
                if (s.count(k)) result++;
            }
        }
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
