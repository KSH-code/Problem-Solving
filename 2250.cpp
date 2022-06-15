#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

const int MAX = 1e4;

pair<int,int> nodes[MAX+1];
pair<int,int> levels[MAX+1];
pair<int,int> counts[MAX+1];

int traverse(int x) {
    auto &[f,s] = counts[x];
    if (f+s > 0) return f+s;

    auto [l, r] = nodes[x];
    f = l == -1 ? 0 : 1 + traverse(l);
    s = r == -1 ? 0 : 1 + traverse(r);
    return f + s;
}

void finalize(int level, int x, int l, int r) {
    if (x == -1) return;

    auto [left_count, right_count] = counts[x];
    finalize(level+1, nodes[x].first, l, l+left_count-1);
    finalize(level+1, nodes[x].second, l+left_count+1, r);

    auto &[low,high] = levels[level];
    low = min(low, l + left_count);
    high = max(high, l + left_count);
}

void solve(){
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        int t; cin >> t;
        auto &[l,r] = nodes[t];
        cin >> l >> r;
    }

    for (int i = 1; i <= N; i++) levels[i] = {MAX, -1};

    int root = 1;
    for (; root <= N; root++) if (traverse(root) == N-1) break;
    finalize(1, root, 1, N);

    int level = 0;
    int result = 0;
    for (int i = 1; i <= N; i++) {
        auto [low, high] = levels[i];
        if (high == -1) continue;
        if (result < high - low + 1) {
            level = i;
            result = high - low + 1;
        }
    }

    cout << level << ' ' << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
