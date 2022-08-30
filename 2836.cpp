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
    int N;
    ll M; cin >> N >> M;
    pair<ll,ll> arr[N]; for (auto &[a,b] : arr)cin>>a>>b;
    sort(arr,arr+N);
    ll c = 0;
    stack<pair<int,int>> s;
    for (int i = 0; i < N; i++) {
        auto [a,b] = arr[i];
        if (c == a) continue;
        if (a > b) {
            int m = b;
            while (s.size() && s.top().second >= b) {
                m = min(m, s.top().first);
                s.pop();
            }
            s.push({m, a});
        }
        c = a;
    }
    ll result = M;
    while (s.size()) {
        result += (s.top().second - s.top().first) * 2;
        s.pop();
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
