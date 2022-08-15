#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};


using pii = pair<int,int>;

void solve(){
    int N; cin >> N;
    pii arr[N]; for(auto &[a,b] : arr) cin >> b >> a;
    sort(arr,arr+N);

    int e = 1e6;

    for (int i = N-1; i >= 0; i--) {
        auto [si,ti] = arr[i];
        int c = min(si, e);
        e = c - ti;
        if (e < 0) {
            cout << -1;
            return;
        }
    }
    cout << e;
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
