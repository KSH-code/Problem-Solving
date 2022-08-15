#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const ll mod = 1e9+7;

ll fa(ll a) {
    if (a == 0) return 0;
    ll r = 1;
    for (ll i = 2; i <= a; i++) r = (r * i) % mod;
    return r;
}

struct Node {
    ll a,b,c;
};

void solve(){
    int N; cin >> N;
    set<ll> zero_check;

    for
    while (N--) {
        ll a;cin >> a;
        if (a == 1) {
            ll b,c; cin >> b >> c;
            if (b%c==0) zero_check.insert(b%c);
            else
        } else {
            ll c; cin >> c;
            if (zero_check.count(c)) cout << "0\n";
            else
        }
    }
    cout << result;
}

int main()
{
    solve();
    return 0;
}
