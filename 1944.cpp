#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    int x,y, c;
};

struct Compare {
    bool operator()(const Node &a, const Node &b) {
        return a.c > b.c;
    }
};

int distances[50][50];
void solve(){
    int N, K; cin >> N >>K;
    string arr[N];
    for (int i = 0; i < N; i++) cin >>arr[i];

    priority_queue<Node, vector<Node>, Compare> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            distances[i][j] = 1e8;
            if (arr[i][j] == 'S') {
                q.push({i, j, 0});
                distances[i][j]=0;
            }
        }
    }

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    int result = 0;
    while (q.size()) {
        auto [x,y,c] = q.top(); q.pop();

        if (distances[x][y] < c) continue;

        if (arr[x][y] == 'K') {
            result += c;
            distances[x][y] = c = 0;
            K--;
        }

        for (int i = 0; i < 4; i++) {
            int nc = c+1;
            int nx = x + dx[i], ny = y + dy[i];
            if (arr[nx][ny] == '1' || distances[nx][ny] <= c) continue;
            if (distances[nx][ny] <= nc) continue;

            distances[nx][ny] = nc;
            q.push({nx, ny, nc});
        }
    }

    if (K>0) result=-1;

    cout << result;

}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
