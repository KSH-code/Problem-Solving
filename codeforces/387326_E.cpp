#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9+7;

void solve(){
    int N, K; cin >> N >> K;
    if (K == 0) {
        cout << 1;
        return;
    }
    ll result = 0;
    ll f = 1; for (int j = 0; j < K; j++) f = f * 2 % mod;
    result += (N/2)*f%mod;
    result%=mod;
    cout << result;
}

int main()
{
    int T; cin >> T;
    while (T--){
        solve();
        cout << '\n';
    }
    return 0;
}
