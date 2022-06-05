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
    vector<vector<int>> edges(N+1);

    queue<int> q;
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        if (p == -1) {
            q.push(i);
            continue;
        }

        edges[p].push_back(i);
    }

    int removed; cin >> removed;

    int result = 0;

    while (q.size()) {
        int x = q.front(); q.pop();
        if (x == removed) continue;

        int count = 0;
        for (auto nx : edges[x]) {
            if (nx == removed) continue;
            q.push(nx);
            count++;
        }
        if (count == 0) result++;
    }

    cout << result;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
