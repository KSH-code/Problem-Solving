#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

const int MAX = 2e5;

int nodes[MAX+1][2];
int counts[MAX+1];

// int dfs(int x) {
//     auto &ref = counts[x];
//     if (ref) return ref;

//     ref = 1
//     for (auto nx : nodes[x]) {
//         if (nx == -1) continue;
//         ref += dfs(nx);
//     }

//     return ref;
// }

void solve(){
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> nodes[i][0] >> nodes[i][1];
    }
    // dfs(1);
    ll K; cin >> K;
    int x = 1;
    while (K) {
        auto [l,r] = nodes[x];
        if (l == -1 && r == -1) {
            cout << x;
            return;
        }

        if (l == -1) {
            x = r;
            continue;
        } else if (r == -1) {
            x = l;
            continue;
        }

        if (K & 1) {
            x = l;
            K = K / 2 + 1;
        } else {
            x = r;
            K = K / 2;
        }
    }
    cout << x;
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
