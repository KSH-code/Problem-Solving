#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

using pii = pair<int,int>;

struct Node {
    pii a[2];
};

void solve(){
    int N, M; cin >> N >> M;
    string arr[N]; for (auto &a : arr) cin >> a;

    Node start;
    int z = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (arr[i][j] == 'o') start.a[z++] = {i,j};

    queue<Node> q; q.push(start);
    for (int result = 1; result <= 10; result++) {
        queue<Node> nq;
        while (q.size()) {
            auto node = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                Node temp;
                int fallen_count = 0;
                for (int j = 0; j < 2; j++) {
                    int nx = node.a[j].first + xxxx[i];
                    int ny = node.a[j].second + yyyy[i];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) fallen_count++;
                    else if (arr[nx][ny] == '#') temp.a[j] = {node.a[j].first,node.a[j].second};
                    else temp.a[j] = {nx,ny};
                }
                if (fallen_count==1) {
                    cout << result;
                    return;
                } else if (fallen_count == 2) continue;
                nq.push(temp);
            }
        }
        q = nq;
    }

    cout << -1;
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
