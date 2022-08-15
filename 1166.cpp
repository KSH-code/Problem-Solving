#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


void solve(){
    ll N,L,W,H; cin >> N >> L >> W >> H;
    long double l = 0, r = L * W / min({L, W, H}) * H;
    cout << r << '\n';

    long double result = 0;
    while (1e-10 <= r - l) {
        long double mid = (l + r) / 2;
        ll c = 1;
        c *= floor(L / mid);
        c *= floor(W / mid);
        c *= floor(H / mid);
        if (c < N) r = mid;
        else l = mid;
    }
    printf("%0.9Lf", l);
}

int main()
{
    // cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
