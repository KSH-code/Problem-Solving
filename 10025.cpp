#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 1e6;

void solve(){
    int N, K; cin >> N >> K;
    ll prefix_sum[MAX+1]; memset(prefix_sum, 0, sizeof prefix_sum);
    vector<pair<int,int>> v;
    for (int i = 0; i < N; i++) {
        int a,b;cin >>a>>b;
        prefix_sum[b] = a;
        v.push_back({b,a});
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= MAX; i++) prefix_sum[i] += prefix_sum[i-1];

    ll result = 0;
    for (int i = 0; i <= MAX; i++) {
        int s = lower_bound(v.begin(), v.end(), pair<int,int>{i-K, 0}) - v.begin();
        int e = lower_bound(v.begin(), v.end(), pair<int,int>{i+K+1, 0}) - v.begin();
        if (v.size() == s) continue;

        if (v.size() == e) result = max(result, prefix_sum[MAX] - prefix_sum[v[s].first-1]);
        else result = max(result, prefix_sum[v[e].first-1] - prefix_sum[v[s].first-1]);
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
