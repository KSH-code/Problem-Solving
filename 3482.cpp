#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0};
int yyyy[]={0,1,0,-1};

const int MAX = 1000;

typedef pair<int,int> pii;

void solve(){
    int N, M; cin >> M >> N;
    string arr[N];
    for (int i = 0; i < N; i++) cin >> arr[i];

    vector<vector<int>> edges(MAX*MAX);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == '.')
            for (int k = 0; k < 4; k++) {
                auto nx = i+xxxx[k];
                auto ny = j+yyyy[k];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if (arr[nx][ny] == '#') continue;

                edges[MAX*i+j].push_back(nx*MAX+ny);
            }
        }
    }

    int distances[MAX*MAX]; memset(distances, -1, sizeof distances);
    queue<int> q;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (q.empty() && arr[i][j] == '.') q.push(i*MAX+j);
    distances[q.front()] = 0;

    int result = 0;
    int next = 0;
    while (q.size()) {
        auto x = q.front(); q.pop();
        int d = distances[x];

        if (result < d) {
            result = d;
            next = x;
        }

        for (auto nx : edges[x]) {
            int &nd = distances[nx];
            if (nd == -1 || nd > d+1) {
                nd = d+1;
                q.push(nx);
            }
        }
    }

    memset(distances, -1, sizeof distances); q.push(next); distances[next] = 0;

    while (q.size()) {
        auto x = q.front(); q.pop();
        int d = distances[x];
        for (auto nx : edges[x]) {
            int &nd = distances[nx];
            if (nd == -1 || nd > d+1) {
                nd = d+1;
                q.push(nx);
            }
        }
    }

    printf("Maximum rope length is %d.\n", *max_element(distances, distances+MAX*MAX));
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
