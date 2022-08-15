#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 1e5;
int parent[MAX+1];
ll counts[MAX+1];

int find(int x) {
    if (parent[x] == x) return x;
    counts[parent[x]] += counts[x];
    counts[x] = 0;
    return parent[x] = find(parent[x]);
}

ll merge(int x, int y) {
    if (find(y) == find(x)) return 0;
    ll r = counts[find(y)] * counts[find(x)];
    parent[find(y)] = parent[find(x)];
    find(y);
    return r;
}

void solve(){
    int N, M, Q;
    cin >> N >> M >> Q;

    for (int i = 1; i <= N; i++) {
        parent[i] = i; counts[i]++;
    }

    bool visited[M]; memset(visited, 0, sizeof visited);
    pair<int,int> arr[M];
    for (auto &[a,b] : arr) cin >> a >> b;

    stack<int> s;
    for (int i = 0; i < Q; i++) {
        int t; cin >> t;
        visited[t-1] = true;
        s.push(t-1);
    }

    for (int i = 0; i < M; i++) {
        if (visited[i]) continue;
        auto [a,b] = arr[i];
        merge(a,b);
    }

    ll result = 0;
    while (s.size()) {
        auto [a,b] = arr[s.top()];
        ll t = merge(a,b);
        result += t;
        s.pop();
    }
    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
