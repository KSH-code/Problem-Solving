#include <bits/stdc++.h>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;


int xxxx[]={-1,0,1,0,-1,1,1,-1};
int yyyy[]={0,1,0,-1,-1,1,-1,1};

struct Node {
    int A, B, count;
    bool A_MOVE;
};

void solve(){
    int N, A, B; cin >> N >> A >> B;
    int DA, DB; cin >> DA >> DB;
    bool visited[N+1][N+1][2]; memset(visited, 0, sizeof visited);
    queue<Node> q;
    q.push({A,B,0,1});
    while (q.size()) {
        auto [A,B,c,m] = q.front(); q.pop();
        if (m) {
            int nx;
            nx = (A + DA);
            if (nx > N) nx = nx%N;
            if (!visited[nx][B][m]) {
                if (nx == B) {
                    cout << c+1;
                    return;
                }
                visited[nx][B][m] = 1;
                q.push({nx,B,c+1,0});
            }
            nx = (N - DA + A);
            if (nx > N) nx = nx%N;
            if (!visited[nx][B][m]) {
                if (nx == B) {
                    cout << c+1;
                    return;
                }
                visited[nx][B][m] = 1;
                q.push({nx,B,c+1,0});
            }
        } else {
            int nx;
            nx = (B + DB);
            if (nx > N) nx = nx%N;
            if (!visited[A][nx][m]) {
                if (nx == A) {
                    cout << c+1;
                    return;
                }
                visited[A][nx][m] = 1;
                q.push({A,nx,c+1,1});
            }
            nx = (N - DB + B);
            if (nx > N) nx = nx%N;
            if (!visited[A][nx][m]) {
                if (nx == A) {
                    cout << c+1;
                    return;
                }
                visited[A][nx][m] = 1;
                q.push({A,nx,c+1,1});
            }
        }
    }
    cout << "Evil Galazy";
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
