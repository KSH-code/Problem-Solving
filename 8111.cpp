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
    int N; cin >> N; if (N == 1) {
        cout << 1;
        return;
    }
    int arr[N+1][2];
    memset(arr, -1, sizeof arr);

    queue<int> q; q.push(1);
    bool visited[N+1]; memset(visited, 0, sizeof visited);
    visited[1]=true;
    while (q.size()) {
        int x = q.front(); q.pop();
        int xx[] = {x*10%N, (x*10+1)%N};
        for (int i = 0; i < 2; i++) {
            auto nx = xx[i];
            if (visited[nx]) continue;
            visited[nx]=true;
            q.push(nx);
            arr[nx][i]=x;
            if (nx == 0) {
                auto c = nx;
                stack<int> s;
                while (c != 1) {
                    if (arr[c][0] != -1) s.push(0);
                    else s.push(1);
                    c = max(arr[c][0], arr[c][1]);
                }
                s.push(1);
                while (s.size()) {
                    cout << s.top();
                    s.pop();
                }
                return;
            }
        }
    }
    cout << "BRAK";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N; cin >> N;

    while(N--) {
        solve();
        cout << '\n';
    }
    return 0;
}
