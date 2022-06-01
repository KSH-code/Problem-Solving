#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

void solve(){
    ll N, M; cin >> N >> M;
    if (M >= N) {
        cout << N;
        return;
    }
    ll arr[M]; for (int i = 0; i < M; i++) cin >> arr[i];

    ll l = 0, r = N*2e5;
    while (l + 1 < r) {
        ll m = (l+r)/2;
        ll count = 0;
        for (int i = 0; i < M; i++) count += m/arr[i]+1;

        if (count < N) {
            l = m;
        } else {
            r = m;
        }
    }
    for (int i = 0; i < M; i++) N -= (r-1)/arr[i]+1;
    for (int i = 0; i < M; i++) {
        if (r%arr[i]==0) N--;
        if (N<=0) {
            cout <<i+1;
            return;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
