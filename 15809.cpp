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
int parents[MAX+1];
int counts[MAX+1];

int find(int x) {
    if (parents[x] == x) return x;
    counts[parents[x]] += counts[x];
    counts[x] = 0;
    return parents[x] = find(parents[x]);
}

void solve(){
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parents[i] = i;
        cin >> counts[i];
    }
    while (M--) {
        int O, P, Q; cin >> O >> P >> Q;
        if (O == 2) {
            counts[find(Q)] = abs(counts[find(P)] - counts[find(Q)]);
            counts[find(P)] = 0;
        }
        parents[find(P)] = find(Q);
        find(P);
    }
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        if (counts[find(i)]) {
            v.push_back(counts[find(i)]);
            counts[find(i)] = 0;
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto a : v) cout << a << ' ';
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
