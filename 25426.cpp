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
    int N; cin >> N;
    pair<ll,ll> arr[N]; for (auto &[a,b] : arr) cin >> a >> b;
    sort(arr, arr+N);
    ll result = 0;
    for (int i = N-1; i >= 0; i--) {
        auto [a,b] = arr[i];
        result += a * (i + 1) + b;
    }

    cout << result;
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
