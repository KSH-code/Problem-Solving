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
    int N, K; cin >> N >> K;
    bool visited[N]; memset(visited, 0, sizeof visited);
    int b_count = 0;
    for (int i = 1; i <= N; i++) if ((N - i) * i >= K) {
        b_count = i;
        break;
    }
    if (!b_count) {
        cout << -1;
        return;
    }

    for (int i = 0; i < b_count; i++) {
        visited[N - i - 1] = true;
    }

    int T = b_count * (N - b_count);
    int a_min = 0;
    int b_min = N - b_count;
    while (T > K) {
        int t = min(N - b_count, T - K);
        for (int i = b_min - 1; i >= 0; i--) {
            if (!visited[i]) t--;
            if (!t) {
                swap(visited[b_min], visited[i]);
                break;
            }
        }
        T -= N - b_count;
        a_min++;
        b_min++;
    }

    for (int i = 0; i < N; i++) if (!visited[i]) cout << "A"; else cout << "B";
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
