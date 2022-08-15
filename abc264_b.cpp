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
    int L, R; cin >> L >> R;
    for (int i = 0; i < 2; i++) {
        swap(L, R);
        int T = L;
        if (T > 8) T = 8 - T;
        if (T&1) {
            if ((R & 1) || (T<=R&&15-T+1>=R)) {
                cout << "black";
                return;
            }
        }
    }
    cout << "white";
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
