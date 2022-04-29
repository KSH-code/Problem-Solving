#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
    ll N; cin >> N;
    ll five = 0;
    for (ll i = 5; i <= N; i*=5) five += N/i;
    cout << five;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while(T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
