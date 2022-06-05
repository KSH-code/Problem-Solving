#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

const ll MOD = 1e9+7;

ll pow(int x) {
    if (x <= 0) return 1;
    ll t = 1;
    if (x & 1) t *= 2;
    ll c = pow(x/2);
    return t * c * c % MOD;
}

void solve(){
    ll result; cin >> result;
    cout << pow(result-2)%MOD;
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
