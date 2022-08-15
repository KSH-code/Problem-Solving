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
    ll N, K; cin >> N >> K;
    ll A[N]; for (auto &a : A) cin >> a;
    int s=0,e=0;
    int bit_check[30]; memset(bit_check, -1, sizeof bit_check);
    ll check = A[0];
    for (int i = 0; i < 30; i++) if (check & 1 << i) bit_check[i] = 0;
    while (s <= e) {
        if (check == K) {
            cout << s+1 << ' ' << e+1;
            return;
        }
        bool p = false;
        for (int i = 0; i < 30; i++) p |= (check & 1 << i) && !(K & 1 << i);
        if ((p && s < e) || e == N-1) {
            for (int i = 0; i < 30; i++) if (bit_check[i] == s) check -= 1 << i;
            s++;
        } else {
            e++;
            check |= A[e];
            for (int i = 0; i < 30; i++) if (A[e] & 1 << i) bit_check[i] = e;
        }
    }
    cout << -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    // cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
