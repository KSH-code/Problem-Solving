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
    ll N, M, K; cin >> N >> M >> K;

    ll arr[K]; for (auto &a : arr) cin >> a;
    ll check;

    for (int k = 0; k < 2; k++) {
        swap(N, M);
        check = M;
        bool odd = M % 2 == 0;
        for (int i = 0; i < K; i++) {
            if (arr[i] / N >= 2) check -= arr[i] / N;
            if (arr[i] / N > 2) odd = true;
        }
        if (check <= 0 && odd) {
            cout << "Yes";
            return;
        }
    }

    cout << "No";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T=1;
    cin >>T;
    while (T--) {
        solve();
        cout << '\n';
    }
    return 0;
}
