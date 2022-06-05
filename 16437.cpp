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
    int N; cin >> N;
    int parents[N+1];
    int child_counts[N+1]; memset(child_counts, 0, sizeof child_counts);
    char types[N+1];
    ll counts[N+1];
    memset(counts, 0, sizeof counts);
    for (int i = 2; i <= N; i++) {
        cin >> types[i];
        cin >> counts[i];
        if (types[i] == 'W') counts[i] *= -1;
        cin >> parents[i];
        child_counts[parents[i]]++;
    }

    queue<int> q;
    for (int i = 2; i <= N; i++) if (!child_counts[i]) q.push(i);

    while (q.size()) {
        auto x = q.front(); q.pop();
        if (x == 1) continue;

        auto &c = counts[x];
        c = max(c, 0LL);

        auto nx = parents[x];
        counts[nx] += c;

        if (--child_counts[nx] == 0) q.push(nx);
    }

    cout << counts[1];
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
