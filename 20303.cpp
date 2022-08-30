#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 3e4;
int arr[MAX+1];
int parent[MAX+1];
int counts[MAX+1];

int find(int x) {
    if (parent[x] == x) return x;
    counts[parent[x]] += counts[x];
    arr[parent[x]] += arr[x];
    counts[x] = 0;
    arr[x] = 0;
    return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
    parent[find(x)] = find(y);
    find(x);
}

void solve(){
    int N, M, K; cin >> N >> M >>K;
    for (int i = 1; i <= N; i++) cin >> arr[i], parent[i] = i, counts[i] = 1;

    while (M--) {
        int a,b; cin >> a >> b;
        merge(a,b);
    }

    vector<int> v;
    for (int i = 1; i <= N; i++) if (i == find(i)) v.push_back(i);
    int dp[K]; memset(dp, 0, sizeof dp);

    for (auto cur : v) {
        int c = counts[cur];
        int d = arr[cur];
        for (int i = K; i >= c; i--) {
            dp[i] = max(dp[i], dp[i - c] + d);
        }
    }
    cout << *max_element(dp, dp + K);
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
