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
    int N; cin >> N;
    int arr[N]; for (auto &a : arr) cin >> a;

    vector<vector<int>> edges(N+1);
    for (int i = 1; i <= N; i++) {
        int c; cin >> c;
        while(c--) {
            int z; cin >> z;
            edges[i].push_back(z);
        }
    }

    int result = -1;
    for (int i = 1; i < (1<<N); i++) {
        int visited[N+1]; memset(visited, -1, sizeof visited);
        int r = 0;
        bool found = true;
        for (int j = 0; j < N; j++) {
            if (i & 1 << j) {
                visited[j+1] = 1, r += arr[j];
            }
        }
        queue<int> q;
        for (int j = 1; j <= N; j++) if (visited[j] == 1) {
            q.push(j);
            connected[j] = 1;
            break;
        }

        bool connected[N+1]; memset(connected, 0, sizeof connected);
        while (q.size()) {
            auto x = q.front(); q.pop();
            for (auto nx : edges[x]) if (!connected[nx] && visited[nx] == 1) {
                connected[nx] = 1;
                q.push(nx);
            }
        }
        for (int j = 1; j <= N; j++) if (visited[j] == 1 && !connected[j]) found = false;

        if (!found) continue;

        int rx = 0;
        for (int j = 1; j <= N; j++) if (visited[j] == -1) {
            q.push(j);
            visited[j] = 0;
            rx += arr[j-1];
            break;
        }

        if (q.empty()) continue;

        while (q.size()) {
            auto x = q.front(); q.pop();
            for (auto nx : edges[x]) if (visited[nx] == -1) {
                rx += arr[nx-1];
                visited[nx] = 0;
                q.push(nx);
            }
        }

        for (int j = 1; j <= N; j++) found &= visited[j] != -1;

        if (found) {
            if (result == -1) result = abs(rx - r);
            result = min(abs(rx - r), result);
        }
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
