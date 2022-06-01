#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

ll lcm(ll a, ll b) {
    return a * b / gcd(a,b);
}

void solve(){
    ll a1,a2,a3; cin >> a1 >> a2 >> a3;
    ll b1,b2,b3; cin >> b1 >> b2 >> b3;
    ll c1,c2,c3; cin >> c1 >> c2 >> c3;

    ll l = lcm(a1,b1);

    for (ll i = 0; i < l; i++) {
        if (a2 <= i % a1 && a3 >= i % a1) {
            if (b2 <= i % b1 && b3 >= i % b1) {
                if (c2 <= i % c1 && c3 >= i % c1) {
                    cout << i;
                    return;
                }
            }
        }
    }
    cout << -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
